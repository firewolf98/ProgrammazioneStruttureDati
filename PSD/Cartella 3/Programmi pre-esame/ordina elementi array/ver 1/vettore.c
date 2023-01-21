#include <stdio.h> 
#include "vettore.h"
#include "utile.h"

int minimo_i(int a[],int i,int n);

void input_array(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Elemento di posizione %d:\n",i);
		scanf("%d",&a[i]);
	}
}

void output_array(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("Elemento di posizione %d: %d\n",i,a[i]);
}

void ordina_array(int a[],int n)
{
	int i,p;
	for(i=0;i<n;i++)
	{
		p=minimo_i(a,i,n);
		scambia(&a[i],&a[p]);
	}
}

int minimo_i(int a[],int i,int n)
{
	int j,min,pmin;
	min=a[i];
	pmin=i;
	for(j=i+1;j<n;j++)
		if(a[j]<min)
		{
			min=a[j];
			pmin=j;
		}
	return (pmin);
}

int ricerca_array(int a[],int n,int elem)
{
	int i=0;
	int trovato=0;
	while(i<n && !trovato)
		if(a[i]==elem)
			trovato=1;
		else
			i++;
	return (trovato ?i:-1);
}

int minimo_array(int a[],int n)
{
	int i,pmin;
	pmin=0;
	for(i=1;i<n;i++)
		if(a[i]<a[pmin])
			pmin=i;
	return pmin;
}
