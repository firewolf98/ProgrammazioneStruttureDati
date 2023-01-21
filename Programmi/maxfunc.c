#include <stdio.h>
#include <math.h>
#define MAX 7

void input(int[]);
int massimo(int[]);

void input(int a[]) {
int i;
for(i=0;i<MAX;i++) {
printf("Inserisci un valore:\n");
scanf("%d",&a[i]); } }

int massimo(int a[]) {
int i,mas=0;
for(i=0;i<MAX;i++) {
if(a[i]>mas)
mas=a[i]; }
return mas; }

int main(void) {
int mas,a[MAX];
input(a);
mas=massimo(a);
printf("Il massimo è: %d\n",mas); }
