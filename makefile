

all: box.exe simplewindow.exe welcome.exe
	make box.exe
	make simplewindow.exe
	make welcome.exe

box.exe:  box.c
	gcc -mwindows -o box.exe box.c
	strip box.exe


simplewindow.exe: simplewindow.c
	gcc -mwindows -o simplewindow.exe simplewindow.c
	strip simplewindow.exe


welcome.exe: welcome.c
	gcc -mwindows -o welcome.exe welcome.c
	strip welcome.exe

