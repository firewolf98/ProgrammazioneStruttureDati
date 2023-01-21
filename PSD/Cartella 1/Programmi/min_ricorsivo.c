#include <stdio.h>

int min_ricorsivo(int [], int);
int search ( int array[], int dim, int x );
int gina ( int array[], int dim, int x);
int pari( int array[], int dim);
int prodotto ( int array[], int dim);

int main(){

	printf("Inserisci numeri nell'array: ");
	
	int array[5];
	
	for ( int i = 0; i < 5; i++ )
		scanf("%d", &array[i]);
		
	int min = min_ricorsivo(array, 5);
	printf("%d", min);
	
	int s = search(array, 5, 2);
	if(s==1) 
		printf("SI");
	else printf("NO");
	
	int g = gina(array, 5, 2);
		if(g==1) 
		printf("SI");
	else printf("NO");
	
	int p = pari(array, 5);
	printf("%d", p);
	
	int prod = prodotto (array, 5);
	printf("%d", prod);
}

int min_ricorsivo ( int array[], int dim ){
	
	int min;
	if ( dim == 1 )
		return array[0];
	
	else{
		min = min_ricorsivo(array, dim-1);
		
		if (array[dim-1] < min )
			return array[dim-1];
		else return min;
	}
}
		
int search ( int array[], int dim, int x ){

	if ( dim == 0 )
		return 0;
	if ( array[dim] == x )
		return 1;
	else
		return search(array, dim-1, x);
}

int gina ( int array[], int dim, int x){

	if ( dim == 0 )
		return 0;
	if ( dim == 1 )	{
		return array[dim-1]>x;
	}
	else
		return array[dim-1]>x && gina(array, dim-1, x);
}

int pari( int array[], int dim){

	if ( dim == 0 )
		return 0;
		
	else if(array[dim-1]%2 == 0)
		return 1+pari(array, dim-1);
	else 
		return pari(array, dim -1);

}

int prodotto ( int array[], int dim){
	
	if ( dim == 0 )
		return 0;
	if ( dim == 1 )
		return array[dim-1];
	
	if (dim%2==0)
		return array[dim]*prodotto(array, dim-1);
	else if (dim%2!=0)
		return prodotto(array, dim-1);
}
