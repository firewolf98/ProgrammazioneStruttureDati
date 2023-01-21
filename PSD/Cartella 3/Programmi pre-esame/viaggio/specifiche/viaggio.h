/*
	specifica sintattica:
		tipi:
			tipo di riferimento: viaggio
			tipi usati:stringa,intero
		operatori:
			newviaggio(stringa,stringa,intero,intero,intero)->viaggio
			inputviaggio()->viaggio
			outputviaggio(viaggio)
			getkey(viaggio)->stringa
	specifica semantica:
		tipi:
			viaggio è l'insieme delle quintuple v=(codice,localita,durata,prezzo,posti),dove:
				codice e localita sono stringhe e durata prezzo e posti sono interi
		operatori:
			newviaggio(cod,loc,dur,price,pos)->v
				post: v=(cod,loc,dur,price,pos)
			inputviaggio()->v
				post: v=(cod,loc,dur,price,pos)
			getkey(v)->a
				post: v=(cod,loc,dur,price,pos) AND a=cod


*/

typedef struct viaggio *viaggio;
viaggio NewViaggio(char cod[],char localita[],int dur,int price,int posti);
viaggio InputViaggio();
void OutputViaggio(viaggio v);
char *getKey(viaggio v);
