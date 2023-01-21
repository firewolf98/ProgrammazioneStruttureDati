test_ordina.exe: test_ordina.o intlib.o ordinamento.o filelib.o
	gcc test_ordina.c ../../librerie/intlib.c ../../librerie/ordinamento.c ../../librerie/filelib.c -o test_ordina.exe
test_ordina.o: test_ordina.c 
	gcc -c test_ordina.c
intlib.o: ../../librerie/intlib.c
	gcc -c ../../librerie/intlib.c
ordinamento.o: ../../librerie/ordinamento.c
	gcc -c ../../librerie/ordinamento.c
filelib.o: ../../librerie/filelib.o
	gcc -c ../../librerie/filelib.c
clean:
	rm -f ../../librerie/filelib.o ordinamento.o intlib.o test_ordina.o 
