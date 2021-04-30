
// gcc -mconsole test_gdi.c -lgdi32
#include <stdio.h>
#include <windows.h>

int main(void)
{
    puts("hi");
    MessageBox(NULL, "test", "test", NULL);
    GetStockObject(0);
    return 0;
}
