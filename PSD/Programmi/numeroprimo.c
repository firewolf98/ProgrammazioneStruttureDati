#include <stdio.h>
int main(void) 
{
int s,r,i,n;
printf("Inserisci il numero N\n");
scanf("%d",&n);
i=1;
s=0;

switch(n) 
	{
	case 0: printf("Il numero non è primo\n"); break; 
	case 1: printf("Il numero non è primo\n"); break; 
	
default: 
	while(i<=n) 
		{
		r=n%i; 

		if(r==0) 
			{
			s=s+1;
			} 
		i=i+1;
		}

		if(s==2)
			{		 
			printf ("Il numero è primo!\n");
			}
		else
		printf("Il numero non è primo!\n");
	break; 
	}

return 0; 
}
