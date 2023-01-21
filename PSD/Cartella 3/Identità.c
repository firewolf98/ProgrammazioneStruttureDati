#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define e 20

typedef struct Identity {
char name[20];
char surname[20];
int *age;}Identity;

int main (void){
char nome[20];
Identity person[2];
int i,t=0;
for(i=0;i<2;i++){
printf ("Inserisci Nome:\n");
scanf ("%s",&person->name[i]);
printf ("Inserisci Surname:\n");
scanf ("%s",&person->surname[i]);
printf("Inserisci età:\n");
scanf ("%d",&person->age[i]);
}
printf ("Inserisci Nome Persona che cerchi:\n");
scanf ("%s",nome);
for(i=0;i<2;i++){
t=strcmp(nome, &person->name[i]);
if(t==1)
printf("La sua età è: %d\n", person->age[i]);}}

