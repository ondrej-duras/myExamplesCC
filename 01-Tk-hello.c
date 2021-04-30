#include <stdio.h>
#include <stdlib.h>
#include <tcl.h>
#include <tk.h>

/*
  https://www.tcl.tk/man/tcl/TkLib/contents.htm
  gcc -mconsole -o hello.exe hello.c -ltk -ltcl
*/

int main(int argc,char **argv) {
  int wh;
  Tcl_Interp *interp = Tcl_CreateInterp();
  wh=Tk_Init(interp);
  printf("%s","Hello world !\n");
  Tcl_Eval(interp,
  "package require Tk\n"
  "proc hello {} {\n"
  "  puts \"hello\"\n"
  "}\n"
  "button .b -text \"hello\" -command hello\n"
  "pack .b -padx 20 -pady 5\n"
  );
  Tk_MainLoop();
  Tcl_DeleteInterp(interp);
  exit(0);
}
