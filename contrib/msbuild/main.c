#include <windows.h>

int main(int argc, const char **argv);
void msvc_startup();
int wmain()
{
	msvc_startup();
	return main(__argc, __argv);
}

#include "compat.c"