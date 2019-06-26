#pragma once

#include <cstdint>


class Hooks {
public:
	void Init( );
	bool HandleUpper(bool, bool);

public:
	~Hooks( );

private:
	static std::uintptr_t KeyboardHook( std::int32_t, std::uint32_t, std::uintptr_t );

private:
	void *original_hook_ { };

};

extern Hooks g_hooks;
