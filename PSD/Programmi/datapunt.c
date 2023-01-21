#include <stdio.h>
#define MAX 12

void split_date(int,int*,int*);

void split_date(int day_of_year, int *month, int *day) {
int i=0,vet[MAX]={31,28,31,30,31,30,31,31,30,31,30,31};
while(day_of_year>vet[i]) {
day_of_year-=vet[i];
i++;}
*day=day_of_year; 
*month=i+1;}

int main(void) {
int giorno, month, day;
printf("Inserisci il giorno:\n");
scanf("%d",&giorno);
split_date(giorno,&month,&day);
printf("Il %d° giorno dell'anno è il %d del %d° mese\n",giorno,day,month); }
