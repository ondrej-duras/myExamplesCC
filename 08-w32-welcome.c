#include <windows.h>

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    MessageBox(NULL, "Welcome to Win32 Application Development\n",
	       NULL, MB_OK);

    return 0;
}
