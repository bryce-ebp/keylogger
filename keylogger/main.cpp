#include "hooks.h"
#include "memory.h"


int main() {
	g_hooks.Init();

	MsgStructure msg { };
	while (g_memory.GetMessage(msg)) {
		g_memory.TranslateMessage(&msg);
		g_memory.DispatchMessage(&msg);
	}

	return 0;
}
