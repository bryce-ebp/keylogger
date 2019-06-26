#pragma once

#include "function_defs.h"


class MemoryManager {
public:
	explicit MemoryManager( );

public:
	CallNextHook m_call_next_hook { };
	SetHook m_set_windows_hook { };
	Unhook m_unhook { };

};

extern MemoryManager g_memory;
