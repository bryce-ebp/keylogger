#include "memory.h"
#include <Windows.h>
#include <iostream>


MemoryManager::MemoryManager() {
	// must call in order for User32.dll to get loaded
	// TODO: load it manually later
	{
		MSG msg { };
		DispatchMessage(&msg);
	}

	const auto u32 = GetModuleHandleA("User32.dll");
	if (!u32) {
		std::cout << "Failed to load User32.dll\n";
		return;
	}

	call_next_hook_ = (CallNextHook_t)GetProcAddress(u32, "CallNextHookEx");
	if (!call_next_hook_) {
		std::cout << "Failed at CallNextHookEx\n";
		return;
	}

	set_windows_hook_ = (SetHook_t)GetProcAddress(u32, "SetWindowsHookExW");
	if (!set_windows_hook_) {
		std::cout << "Failed at SetWindowsHookExW\n";
		return;
	}

	unhook_ = (Unhook_t)GetProcAddress(u32, "UnhookWindowsHookEx");
	if(!unhook_) {
		std::cout << "Failed at UnhookWindowsHookEx\n";
		return;
	}
	
	get_message_ = (GetMessage_t)GetProcAddress(u32, "GetMessageW");
	if (!get_message_) {
		std::cout << "Failed at GetMessage\n";
		return;
	}

	translate_message_ = (TranslateMessage_t)GetProcAddress(u32, "TranslateMessage");
	if (!translate_message_) {
		std::cout << "Failed at TranslateMessage\n";
		return;
	}

	dispatch_message_ = (DispatchMessage_t)GetProcAddress(u32, "DispatchMessageW");
	if (!dispatch_message_) {
		std::cout << "Failed at DispatchMessage\n";
		return;
	}
}

MemoryManager g_memory { };
