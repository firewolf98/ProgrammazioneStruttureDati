int.exe: intlib.o int.o
	gcc int.c ../lib/intlib.c -o int.exe
intlib.o: ../lib/intlib.c
	gcc -c ../lib/intlib.c
int.o: int.c ../lib/intlib.c
	gcc -c int.c
clean: 
	rm -f int.o intlib.o int.exe

