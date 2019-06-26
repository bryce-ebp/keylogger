#pragma once

#include <cstdint>


typedef __declspec( dllimport ) long  ( __stdcall *CallNextHook )( void *, std::int32_t, std::uint32_t, std::uintptr_t );
typedef __declspec( dllimport ) void *( __stdcall *SetHook )( std::int32_t, void *, _In_opt_ void *, _In_ std::uintptr_t );
typedef __declspec( dllimport ) int   ( __stdcall *Unhook )( void * );
