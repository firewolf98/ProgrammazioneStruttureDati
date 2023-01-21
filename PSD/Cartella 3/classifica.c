#include <stdio.h>
#include <stdlib.h>
int main(void) {
float vet[15],n,temp,last;
int i,j=15,s;
for(i=0;i<15;i++) 
{
	printf("Inserisci il %d tempo di gara\n",i+1);
	scanf("%f",&vet[i]);
}
last=j;
while(j>=0)
{
	last--;
	for(i=0;i<j-1;i++)
	{
		if(vet[i]>vet[i+1])
		{
			temp=vet[i];
			vet[i]=vet[i+1];
			vet[i+1]=temp;
			
		}
	}
	j=last;
}
for(i=0;i<15;i++)
{
	printf("%f\n",vet[i]);
}

printf("\n");

printf("Inserisci il nuovo tempo\n");
scanf("%f",&n);

for(i=0;i<15;i++)
{
	if(n>=vet[i] && n<=vet[i+1])
	{
		s=i+1;
		for(j=15;j>i;j--)
		{
			vet[j+1]=vet[j];
		}
	exit;
	}
}	
vet[s]=n;	
printf("\nNuova classifica:\n");
for(i=0;i<15;i++)
{
	printf("%f\n",vet[i]);
}
return 0;
}
