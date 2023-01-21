#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"


struct libro
{
	char libro[20];
	int pagine;
	Libro next
};


Libro inseriscilibro(char titolo[],int pagine,Libro head)
{
	Libro nuovo=malloc(sizeof(struct libro));
	strcpy(nuovo->libro,titolo);
	
