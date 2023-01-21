#include <stdio.h>

int fibonacci (int n);

int main(){

	printf("Di quale numero vuoi calcolare la serie? ");
	int n;
	scanf("%d", &n);
	
	int r = fibonacci(n);
	printf("%d", r);
}

int fibonacci(int n){

	if ( n == 1 )
		return 1;
		
	if ( n == 0 ) 
		return 1;
		
	else 
		return (fibonacci(n-1)+fibonacci(n-2));
}
