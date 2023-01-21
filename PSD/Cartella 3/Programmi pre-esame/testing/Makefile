test_ordina_array.exe: test_ordina_array.o intlib.o ordinamento.o file_array.o
	gcc test_ordina_array.c intlib.c ordinamento.c file_array.c -o test_ordina_array.exe
test_ordina.o: test_ordina_array.c 
	gcc -c test_ordina_array.c
intlib.o: intlib.c
	gcc -c intlib.c
ordinamento.o: ordinamento.c
	gcc -c ordinamento.c
file_array.o: file_array.o
	gcc -c file_array.c
clean:
	rm -f file_array.o ordinamento.o intlib.o test_ordina.o 
