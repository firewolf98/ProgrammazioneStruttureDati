#include <stdio.h>
#include "item.h"
#include "gestpren.h"
#include "chainedHash.h"

int main()
{
	int s,n,i,r,t;
	item pren;
	gestione g=NewGestione();
	printf("Cosa vuoi fare?\n 1-Inserisci Prenotazioni\n 2-Servi Cliente\n 3-Visualizza chi sta servendo lo sportello\n 4-Visualizza clienti non ancora serviti\n");
	scanf("%d",&s);
	while(1) 
		switch(s) 
		{
			case 1: 
				printf("Quante prenotazioni vuoi inserire?\n");
				scanf("%d",&n);
				for(i=1;i<=n;i++)
				{
					pren=InputPren(i);
					agg_pren(g,pren);
				}
				break;
			case 2:
				printf("Quale sportello lo deve servire?\n 1-Sportello 1\n 2-Sportello 2");
				scanf("%d",&r);
					//if(r==1)
				break;
			case 3:
				printf("Quale sportello vuoi visualizzare?\n 1-Sportello 1\n 2-Sportello 2");
				scanf("%d",&t);		
				stampapren(t,);
				break;
			case 4:
				outputGest(g);
				break;
			default: 
				printf("Caso non valido.\n")
				exit(1);
		}
}
