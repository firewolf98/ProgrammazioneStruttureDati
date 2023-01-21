main.exe: item.o lista.o menu.o main.o
	gcc item.o lista.o menu.o main.o -o main.exe

item.o: item.c
	gcc -c item.c

lista.o: lista.c item.h
	gcc -c lista.c

menu.o: menu.c
	gcc -c menu.c

main.o: main.c list.h item.h
	gcc -c main.c

clean:
	rm -f item.o lista.o menu.o main.o main.exe
