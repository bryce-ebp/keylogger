#pragma once

#include <cstdint>
#include <Windows.h>


class Hooks {
public:
	void Init( );

public:
	~Hooks( );

private:
	static std::uintptr_t KeyboardHook( std::int32_t, std::uint32_t, std::uintptr_t );

private:
	HHOOK m_original_hook { };

};

extern Hooks g_hooks;
