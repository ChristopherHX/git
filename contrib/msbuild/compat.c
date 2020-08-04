#include <windows.h>

char __strbuf_slopbuf[1];
const char *__empty_argv[] = { 0 };

int main(int argc, const char **argv);
void msvc_startup();
int wmain()
{
	msvc_startup();
	return main(__argc, __argv);
}