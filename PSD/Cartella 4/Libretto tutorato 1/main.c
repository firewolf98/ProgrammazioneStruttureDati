#include <stdio.h>
#include <stdlib.h>
#include "funzionilibretto.h"


int main(int argc,char const *argv[]) 
{
	int sizelist=0;
	Esame head=NULL;
	while(1)
	{
		int sel=0;
		printf("Inserisci 1 per inserire in testa\n");
		printf("Inserisci 2 per inserire in una determinata posizione\n");
		printf("Inserisci 3 per eliminare in testa\n");
		printf("Inserisci 4 per eliminare in una determinata posizione\n");
		scanf("%d",&sel);
		if(sel==1)
		{
			char esame[20];
			int voto=0;
			printf("Nome esame:\n");
			scanf("%s",esame);
			printf("Voto:\n");
			scanf("%d",&voto);
			head=inserisciesame(esame,voto,head);
			if(head!=NULL)
				sizelist++;
		}
		else if(sel==2)
		{
			char esame[20];
			int voto=0;
			int pos=0;
			printf("Nome esame:\n");
			scanf("%s",esame);
			printf("Voto:\n");
			scanf("%d",&voto);
			printf("Inserisci la posizione:\n");
			scanf("%d",&pos);
			if(pos<sizelist)
			{
				head=inserisciesame(esame,voto,head);	
				sizelist++;
			}
		}
		else if(sel==3)
		{
			head=cancellatesta(head);
			sizelist--;
		}
		else if(sel==4)
		{
			if(sizelist>0)
			{
				int pos=0;
				printf("Inserisci la posizione:\n");
				scanf("%d",&pos);
				if(pos>0 && pos<sizelist)
				{
					head=cancellapos(pos,head);
					sizelist--;
				}
			}
		}
	}
return 0;
}
