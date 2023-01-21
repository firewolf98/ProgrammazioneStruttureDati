#include <stdio.h>
#include "item.h"

void inputItem ( item a ){
	scanf("%d", &a);
}
void outputItem ( item a ){
	printf("%d\n", a);
}

int eq( item a, item b ){
	if (a==b)
		return 1;
	return 0;
}

item cloneItem( item a ){

	return (a);
}

void destroyItem( item *a ){

}
