#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct calciatore{
char nome[20];
char cognome[20];
int numero;
char ruolo[2];}calciatore;


void inserisci(calciatore);


int main(void) {
int n,younger;
calciatore inter;
printf("Quanti giocatori vuoi inserire?\n");
scanf("%d",&n);
while(n>0) {
inserisci(inter);
n--; } }


void inserisci(calciatore inter) {
printf("Inserisci Nome Cognome Numero e Ruolo  del calciatore:\n(PP=Portiere, DC=Difensore, CC=Centrocampista, AT=Attaccante)\n");
scanf("%s",inter.nome);
scanf("%s",inter.cognome);
scanf("%d",&inter.numero);
scanf("%s",inter.ruolo); }
