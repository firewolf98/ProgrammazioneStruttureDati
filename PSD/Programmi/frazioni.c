#include <stdio.h>
#include <stdlib.h>
typedef struct skriniar{
int denominatore;
int numeratore;} skriniar;
skriniar somma(skriniar,skriniar);
int main(void) {
skriniar perisic,icardi,ranocchia;
printf("Inserisci la prima frazione\n");
scanf("%d",&perisic.numeratore);
scanf("%d",&perisic.denominatore);
printf("Inserisci la seconda frazione\n");
scanf("%d",&icardi.numeratore);
scanf("%d",&icardi.denominatore);
ranocchia=somma(perisic,icardi);
printf("La somma è: %d/%d\n",ranocchia.numeratore,ranocchia.denominatore);
return 0; }

skriniar somma(skriniar miranda,skriniar karamoh) {
skriniar handanovic;
handanovic.denominatore=miranda.denominatore*karamoh.denominatore;
handanovic.numeratore=handanovic.denominatore/miranda.denominatore*miranda.numeratore+handanovic.denominatore/karamoh.denominatore*karamoh.numeratore;
return handanovic;}
