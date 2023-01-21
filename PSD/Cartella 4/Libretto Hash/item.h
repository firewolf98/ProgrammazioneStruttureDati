/*
– Tipo: esame
– Tipi utilizzati: stringa, intero

	•Specifica semantica
		–Esame è l'insieme delle quintuple nome insegnamento, numero cfu, voto, lode, data dove:
			-nome insegnamento e lode sono delle stringhe mentre numero, voto e data sono degli interi
	
	•Specifica sintattica (Operatori)
		–newSquadra(stringa, intero,intero, intero,intero)->squadra
		–inputSquadra() -> item
		–cmpItem(squadra, squadra)->int
		–getKey(v) -> stringa
		–aggiornaReti(item,intero, intero) ->
		–aggiungiPunti(item, item, intero, intero) ->
		–incrementaPartite(item) ->
		-compare(item, item) -> intero

	•Specifica semantica (Operatori)
		-newEsame(nome_ins, cfu, voto, lode, data)->s
			•Post: s=(nome_ins, cfu, voto, lode, data)

		–inputEsame() -> s
			•Post: s=(nome_ins, cfu, voto, lode, data)

		-cmpItem(s1, s2)->b
			•Pre: s1=(nome_ins1, cfu1, voto1, lode1, data1) AND s2=(nome_ins2, cfu2, voto2, lode2, data2)
			•Post: b<0 se nome_ins1<nome_ins2, b=0 se nome_ins1=nome_ins2, b>0 se nome_ins1>nome_ins2

		– getKey(v) -> s
			•Post: v=(nome_ins, cfu, voto, lode, data) AND s=nome_ins
*/
typedef struct esame *item;

item newEsame(char *nom, int num_cfu, int voto, char *lode, int data);

item inputEsame();

void outputEsame(item v);

int cmpItem(item a, item b);

char *getKey(item value);
