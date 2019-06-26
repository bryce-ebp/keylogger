#pragma once

#include "function_defs.h"


class MemoryManager {
public:
	explicit MemoryManager( );

public:
	std::uintptr_t CallNextHook(const void *original_hook, const std::int32_t code, const std::uint32_t wparam, const std::uintptr_t lparam) const {
		return call_next_hook_(original_hook, code, wparam, lparam);
	}

	void *SetHook(const std::int32_t hook_id, const void *hooked_fn) const {
		return set_windows_hook_(hook_id, hooked_fn, nullptr, 0u);
	}

	void Unhook(const void *original_hook) const {
		unhook_(original_hook);
	}

	std::int32_t GetMessage(const MsgStructure &msg) const {
		return get_message_(msg, nullptr, 0u, 0u);
	}
	
	void TranslateMessage(const MsgStructure *msg) const {
		translate_message_(msg);
	}

	void DispatchMessage(const MsgStructure *msg) const {
		dispatch_message_(msg);
	}

protected:
	CallNextHook_t call_next_hook_ { };
	SetHook_t set_windows_hook_ { };
	Unhook_t unhook_ { };
	GetMessage_t get_message_ { };
	TranslateMessage_t translate_message_ { };
	DispatchMessage_t dispatch_message_ { };

};

extern MemoryManager g_memory;
