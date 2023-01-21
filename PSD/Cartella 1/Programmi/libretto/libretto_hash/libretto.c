#include <string.h>
#include <stdio.h>
#include "key.h"
#include "item.h"
#include "htable.h"
#include "libretto.h"

libretto newLibretto (int dim){
	libretto l;
	l = newHash(dim);
	return l;
}

int insertLibretto(libretto l){
	item e = inputItem();
	if ( e != NULL ){
		return insertHash(l, e, getISBN(e));
	}
}

item searchLibretto (libretto l, char code[]){
	item res = searchHash(l, code);
	
	if(res != NULL)
		return res;
	else
		return NULLITEM;
}

int removeLibretto(libretto l, char code[]){
	int res = removeHash(l, code);
	return res;
}
