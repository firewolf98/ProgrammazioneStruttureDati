#include <stdio.h>

int main(void) 

	{
	int x,r,s,i,j;
	int a[5],b[5];	
	int c[10];
	int q,p;

	p=0; q=0;
	
	for(x=0;x<5;x++) 
	{
	printf("Inserisci un valore primo vettore\n");
	scanf("%d",&a[x]); 
	}
	
	for(x=0;x<5;x++) 
	{
	printf("Inserisci un valore secondo vettore\n");
	scanf("%d",&b[x]); 
	}
	
	for(x=0;x<5;x++) 
	{
	r=a[x]%2;
		if(r==0) 
		{
		c[p]=a[x];
		p=p+1;
		}
	}
	q=p;
	
	for(x=0;x<5;x++) 
	{
	s=b[x]%2;
		if(s==0)
		{
		c[q]=b[x]; 
		q=q+1;
		}
	}

	for(x=0;x<q;x++) 
	{
	printf("%d\n",c[x]); 
	}

return 0; 
}

  
 
