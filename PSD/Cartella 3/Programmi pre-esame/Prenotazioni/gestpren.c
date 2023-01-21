#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "gestpren.h"
#include "chainedHash.h"
#define MAX 20

struct gestione {
	hashtable prenotazioni;
};

gestione NewGestione()
{
	gestione *nuovo=malloc(sizeof (struct gestione));
	if(nuovo!=NULL)
		nuovo->prenotazioni=newHashtable(MAX);
	return nuovo;
}

int agg_pren(gestione g,item pren) 
{
	if(g==NULL)
		return 0;
	return insertHash(g->prenotazioni,pren);
}

/*item servicliente(int r)
{
	
}


void stampapren(int t,int *i)
{
	prenotazione a=servicliente;
	printf("Lo sportello %d sta servendo: ",t);
	outputItem(a);
	printf("\nNUMERO PRENOTAZIONE: %d",i);
}
*/

int outputGest(gestione g)
{
	if(g==NULL)
		return 0;
	else 
		return outputHash(g->prenotazioni);
} 
