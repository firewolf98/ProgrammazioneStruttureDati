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

int cmpItem ( item val, item val1 ){
	if ( val == val1 )
		return 0;
	if ( val > val1 )
		return 1;
	else
		return -1;
}

item cloneItem( item a ){

	return (a);
}

void destroyItem( item *a ){

}
