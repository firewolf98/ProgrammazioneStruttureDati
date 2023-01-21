ordina.exe: ordina.o intlib.o ordinamento.o filelib.o
	gcc ordina.c ../../librerie/intlib.c ../../librerie/ordinamento.c ../../librerie/filelib.c -o ordina.exe
ordina.o: ordina.c 
	gcc -c ordina.c
intlib.o: ../../librerie/intlib.c
	gcc -c ../../librerie/intlib.c
ordinamento.o: ../../librerie/ordinamento.c
	gcc -c ../../librerie/ordinamento.c
filelib.o: ../../librerie/filelib.o
	gcc -c ../../librerie/filelib.c
clean:
	rm -f ordina.o filelib.o ordinamento.o intlib.o
