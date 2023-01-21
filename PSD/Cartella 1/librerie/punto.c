#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"

struct pto{
	int x;
	int y;
};

punto creapuntonoset(void){
	punto point;
	point = malloc(sizeof(struct pto));
	return point;
}

punto creapunto(void){
	punto point;
	point = malloc(sizeof(struct pto));
	printf("Inserisci la posizione x: ");
	scanf("%d", &point->x);
	printf("Inserisci la posizione y: ");
	scanf("%d", &point->y);
	return point;
}

int distanzapunti(punto a, punto b){
	int dist=0, temp1=0, temp2=0, temp3=0;
	temp1= ((b->x) - (a->x)) * ((b->x) - (a->x));
	temp2 = ((b->y) - (a->y)) * ((b->y) - (a->y));
	temp3 = temp1+temp2;
	dist = sqrt(temp3);
	return dist;
}

void inspto(punto pto){
	printf("Inserisci la x del punto: ");
	scanf("%d", &pto->x);
	printf("Inserisci la y del punto: ");
	scanf("%d", &pto->y);
}

int checkpto(punto indovina, punto tentativo){
	int flag = 0;
	if(tentativo->x==indovina->x && tentativo->y==indovina->y){
		flag = 1;
		return flag;
	} else {
		return flag;
	}
}

void waterfire(punto indovina, punto tentativo){
	if (tentativo->x+1==indovina->x||tentativo->x-1==indovina->x||tentativo->y+1==indovina->y||tentativo->y-1==indovina->y||tentativo->y==indovina->y||tentativo->x==indovina->x){
		printf("FUOCO!\n");
	} else {
		printf("ACQUA!\n");
	}
}
