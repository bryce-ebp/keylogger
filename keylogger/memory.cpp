#include "memory.h"
#include <Windows.h>


MemoryManager::MemoryManager( ) {
	const auto u32 = GetModuleHandleA( "User32.dll" );
	m_call_next_hook = ( CallNextHook )GetProcAddress( u32, "CallNextHookEx" );
	if( !m_call_next_hook ) return;

	m_set_windows_hook = ( SetHook )GetProcAddress( u32, "SetWindowsHookExW" );
	if( !m_set_windows_hook ) return;

	m_unhook = ( Unhook )GetProcAddress( u32, "UnhookWindowsHookEx" );
}

MemoryManager g_memory { };
