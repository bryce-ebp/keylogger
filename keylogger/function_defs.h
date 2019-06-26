#pragma once

#include <cstdint>


class Point {
public:
	std::uintptr_t x_ { };
	std::uintptr_t y_ { };
};

struct MsgStructure {
	void *hwnd_ { };
	std::uint32_t message_ { };
	std::uintptr_t wparam_ { };
	std::uintptr_t lparam_ { };
	std::uint32_t time_ { };
	Point point_ { };
};


using CallNextHook_t = __declspec(dllimport) std::uintptr_t(__stdcall *)(const void *, const std::int32_t, const std::uint32_t, const std::uintptr_t);

using SetHook_t = __declspec(dllimport) void *(__stdcall *)(const std::int32_t, const void *, const void *, std::uintptr_t);

using Unhook_t = __declspec(dllimport) std::int32_t(__stdcall *)(const void *);

using GetMessage_t = __declspec(dllimport) std::int32_t(__stdcall *)(const MsgStructure &, const void *, const std::uint32_t, const std::uint32_t);

using TranslateMessage_t = __declspec(dllimport) std::int32_t(__stdcall *)(const MsgStructure *);

using DispatchMessage_t = __declspec(dllimport) std::int32_t(__stdcall *)(const MsgStructure *);
