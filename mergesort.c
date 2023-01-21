#include <stdio.h>
#include <stdlib.h>

void MergeSort(int a[],int p,int r);
void Merge(int a[],int p,int q,int r);

int main(void)
{
	int i,p,r,a[6],*c;
	for(i=0;i<6;i++)
	{
		printf("Inserisci un numero:\n");
		scanf("%d",&a[i]);
	}
	p=a[0];
	r=a[5];
	MergeSort(a,p,r);
	for(i=0;i<6;i++)
	{
		printf("%d\n",c[i]);
	}
	
}

void MergeSort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		MergeSort(a,p,q);
		MergeSort(a,q+1,r);
		Merge(a,p,q,r);
	}
	return ;
}

void Merge(int a[],int p, int q,int r)
{
	int b[6],i,j,k;
	for(i=p,j=q+1,k=p;i<=q && j<=r;)
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	for(;i<=q;)
		b[k++]=a[i++];
	for(;j<=r;)
		b[k++]=a[j++];
	for(k=p;k<=r;k++)
		a[k]=b[k];
	
}
