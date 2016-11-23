

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

hello0.exe: hello0.c
	gcc -mconsole hello0.c -o hello0.exe -lgdi32

hello2.exe: hello2.cpp
	gcc -mwindows hello2.cpp -o hello2.exe -lgdi32

winhello.exe: winhello.c
	gcc -mwindows winhello.c -o winhello.exe
	strip winhello.exe
