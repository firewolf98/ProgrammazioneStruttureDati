#include <stdio.h> 
#include "vettore.h"
#include "utile.h"

static int minimo_i(int a[],int i,int n);

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

static int minimo_i(int a[],int i,int n)
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

int somma_elem_array(int a[],int n)
{
	int i,sum=0;
	for(i=0;i<n;i++)
		sum+=a[i];
	return sum;
}

void somma_elem(int a[], int b[],int c[],int n)
{
	int i;
	for(i=0;i<n;i++)
		c[i]=a[i]+b[i];
}

void prod_scal_array(int a[],int b[], int c[],int n)
{
	int i;
	for (i=0;i<n;i++)
		c[i]=a[i]*b[i];
}

void inserisci(int a[],int *n,int elem,int pos)
{
	for(int i=*n;i>pos;i--)
		a[i]=a[i-1];
	a[pos]=el;
	(*n)++;
}

int inserisci (int a[],int *n,int elem,int pos)
{
	if(pos<0 || posz*n)
		return 0;
	for(int i=*n;i>pos;i--)
		a[i]=a[i-1];
	a[pos]=elem;
	(*n)++;
	return 1;
}

void elimina(int a[],int *n,int pos)
{
	for(int i=pos;i<*n-1;i++)
		a[i]=a[i+1];
	(*n)--;
}
