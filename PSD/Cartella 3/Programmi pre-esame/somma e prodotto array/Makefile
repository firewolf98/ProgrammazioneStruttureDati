int.exe: intlib.o int.o
	gcc int.c intlib.c -o int.exe
intlib.o: intlib.c
	gcc -c intlib.c
int.o: int.c intlib.c
	gcc -c int.c
clean: 
	rm -f int.o intlib.o int.exe

