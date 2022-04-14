//detectOS.hpp
#include <iostream>
std::string OSType()
{
#ifdef _WIN32
	return "Windows"; //impossible
#elif __linux__
	return "Linux";
#elif __APPLE__
	return "Apple";
#else
	return "Unknown";
#endif // _WIN32
}