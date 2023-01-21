ordina_array.exe: utile.o vettore.o ordina_array.o
			gcc utile.o vettore.o ordina_array.o -o ordina_array.exe

utile.o: utile.c
		gcc -c utile.c

vettore.o: vettore.c utile.h
		gcc -c vettore.c

ordina_array.o: ordina_array.c vettore.h
			gcc -c ordina_array.c

clean: 
	rm -f utile.o vettore.o ordina_array.o ordina_array.exe
