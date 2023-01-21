#include <stdio.h>
#include "utile.h"

void scambia(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
