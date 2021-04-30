#include <windows.h>

LPCTSTR Caption = "Application Programming Interface";

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    MessageBox( NULL,
                "Welcome to Win32 Application Development\n"
                "You will learn about functions, classes, "
                "communication, and other cool stuff\n"
                "Are you ready to rumble!!!!!!!!!!!!!!",
                Caption,
                MB_YESNOCANCEL | MB_ICONQUESTION);

    return 0;
}



