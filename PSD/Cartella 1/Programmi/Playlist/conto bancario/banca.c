#include <string.h>
#include <stdio.h>
#include "key.h"
#include "item.h"
#include "htable.h"
#include "banca.h"

banca newBanca (int dim){
	banca p;
	p = newHash(dim);
	return p;
}

int insertConto(banca p){
	item e = inputItem();
	if ( e != NULL ){
		item res = searchHash(p, getIBAN(e);
		if(res != NULL)
			return insertHash(p, e, getIBAN(e));
	}
	return 0;
}

item searchConto (banca p, char IBAN[]){
	item res = searchHash(p, IBAN);
	
	if(res != NULL)
		return res;
	else
		return NULLITEM;
}

int removeConto(banca p, char IBAN[]){
	int res = searchHash(p, IBAN);
	if(getIBAN(res)>0){
		removeHash(p,IBAN);
		return res;
	}
	return 0;
}

item deposita (banca p, char IBAN[], int saldo){
	if (p == NULL)
		return -1;

	item res = searchConto(p, IBAN);

	if(res != NULL){
		item r = upSaldo(res, saldo);
		return r;
	}
	return NULLITEM;
}

item prelievo(banca p, char IBAN[], int saldo)
//tempo finito
