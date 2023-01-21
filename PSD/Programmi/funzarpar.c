#include <stdio.h>

int riempi(int, int);

int main(void)
{
int i,j;
int a[5];



for(i=0;i<5;i++)

printf("%d",riempi(a[i]));

}

int riempi(int a[5], int i)
{
for(i=0;i<5;i++) 
{
printf("Inserisci numero per il'array");
scanf("%d", &a[i]);
return a[i];
}
}
