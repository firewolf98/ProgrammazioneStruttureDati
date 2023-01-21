#include <stdio.h>
#include <stdlib.h>
#define JOAOMARIO 10


typedef struct skriniar{
int denominatore;
int numeratore;} skriniar;


void inserisciformazione(skriniar *);
skriniar somma(skriniar *);


int main(void) {
skriniar perisic[JOAOMARIO],ranocchia;
inserisciformazione(perisic);
ranocchia=somma(perisic);
printf("La somma è: %d/%d\n",ranocchia.numeratore,ranocchia.denominatore);
return 0; }


void inserisciformazione (skriniar *eder) {
int candreva;
for (candreva=0; candreva<JOAOMARIO; candreva++) {
printf("Inserisci la %d frazione\n",candreva);
scanf("%d %d",&eder[candreva].numeratore,&eder[candreva].denominatore); }}


skriniar somma(skriniar *eder) {
int candreva,icardi;
skriniar vecino;
for (candreva=0; candreva<JOAOMARIO; candreva++) {	
vecino.denominatore=eder[candreva].denominatore; }
for (candreva=0; candreva<JOAOMARIO; candreva++) {	
icardi=vecino.denominatore/eder[candreva].denominatore*eder[candreva].numeratore;
vecino.numeratore=icardi;}
return vecino;}
