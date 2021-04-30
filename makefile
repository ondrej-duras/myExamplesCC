
# potrebne pre fungovanie pkg-config nastroja
#set PKG_CONFIG_PATH=C:\msys64\mingw64\lib\pkgconfig  ... pkg-config

all: all1

all1: 01.exe 02.exe 03.exe 04.exe 05.exe 06.exe 07.exe 08.exe 09.exe

clean:
	rm *.exe

strip:
	strip *.exe

01.exe: 01-Tk-Hello.c
	gcc -mconsole -o 01.exe 01-Tk-Hello.c -ltk -ltcl

02.exe: 02-Gtk-Hello.c
	gcc `pkg-config --cflags gtk+-3.0` -o 02.exe 02-Gtk-Hello.c `pkg-config --libs gtk+-3.0`

03.exe: 03-pcre-exec.c
	gcc -mconsole -Wall 03-pcre-exec.c -o 03.exe -lpcre

04.exe: 04-pcre2-substitute.c
	gcc -mconsole -Wall 04-pcre2-substitute.c -o 04.exe -lpcre2-8

05.exe: 05-w32-box.c
	gcc -mwindows -Wall 05-w32-box.c -o 05.exe

06.exe: 06-w32-simplewindow.c
	gcc -mwindows -Wall 06-w32-simplewindow.c -o 06.exe

07.exe: 07-w32-hellogdi.c
	gcc -mconsole -Wall 07-w32-hellogdi.c -o 07.exe -lgdi32

08.exe: 08-w32-welcome.c
	gcc -mwindows -Wall 08-w32-welcome.c -o 08.exe

09.exe: 09-w32-winhello.c
	gcc -mwindows -Wall 09-w32-winhello.c -o 09.exe

#01-Tk-hello.c
#02-Gtk-Hello.c
#03-pcre-exec.c
#04-pcre2-substitute.c
#05-w32-box.c
#06-w32-simplewindow.c
#07-w32-hellogdi.c

