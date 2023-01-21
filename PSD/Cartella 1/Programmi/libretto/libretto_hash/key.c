#include <string.h>
#include "key.h"

int fhash (int size, key k){
	int val;
	int len = strlen(k);
	val = k[0] + k[len-1] +len;
	
	return (val%size);
}
