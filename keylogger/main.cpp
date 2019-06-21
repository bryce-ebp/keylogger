#include "hooks.h"


int main( ) {
	g_hooks.Init( );
	
	MSG msg { };
	while( GetMessage( &msg, nullptr, 0u, 0u ) ) {
		TranslateMessage( &msg );
		DispatchMessage( &msg );
	}

	return 0;
}
