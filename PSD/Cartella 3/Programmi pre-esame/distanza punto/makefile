distanza_punto.exe: punto.o distanza_punto.o
		gcc punto.o distanza_punto.o -o distanza_punto.exe

punto.o: punto.c
	gcc -c punto.c

distanza_punto.o: distanza_punto.c punto.h
	gcc -c distanza_punto.c

clean:
	rm -f punto.o distanza_punto.o distanza_punto.exe
