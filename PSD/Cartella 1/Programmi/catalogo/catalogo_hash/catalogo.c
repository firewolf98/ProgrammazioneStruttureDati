#include <string.h>
#include <stdio.h>
#include "key.h"
#include "item.h"
#include "htable.h"
#include "catalogo.h"

catalogo newCatalogo (int dim){
	catalogo p;
	p = newHash(dim);
	return p;
}

int insertCatalogo(catalogo p){
	item e = inputItem();
	if ( e != NULL ){
		return insertHash(p, e, getCode(e));
	}
}

item searchCatalogo (catalogo p, char code[]){
	item res = searchHash(p, code);
	
	if(res != NULL)
		return res;
	else
		return NULLITEM;
}

int removeCatalogo(catalogo p, char code[]){
	int res = removeHash(p, code);
	return res;
}

int updatePrezzo (catalogo c, char code[], int price){
	item res = searchCatalogo(c, code);
	if ( res == NULL)
		return -1;
	else{
		upPrice(res, price);
		return 1;
	}
}

int updatePosti(catalogo c,char code[], int posti){
	item res = searchCatalogo(c, code);
	if ( res == NULL)
		return -1;
	
	else{
		upPosti(res,posti);
		return 1;
	}
}
