/*
•Specifica sintattica
– Tipo: squadra
– Tipi utilizzati: stringa, intero

•Specifica semantica
–Squadra è l'insieme delle quintuple nome, partite, punti, reti fatte e reti subite dove:
	-nome è una stringa che rappresenta il nome della squadra;
	-partite è un intero che rappresenta il numero di partite giocate;
	-punti è un intero che rappresenta il numero di punti in classifica della squadra;
	-reti fatte è un intero;
	-reti subite è un intero.


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
-newSquadra(nome, partite, punti, retifatte, retisubite)->s
Post: s=(nome, partite, punti, retifatte, retisubite)

–inputSquadra() -> s
	•Post: s=(nome, partite, punti, reti fatte, reti subite)

-cmpItem(s1, s2)->b
Pre: s1=(nome1, partite2, punti1, retifatte1, retisubite1) AND s2=(nome2, partite2,  punti2, retifatte2, retisubite2)
Post: b<0 se nome1<nome2, b=0 se nome1=nome2, b>0 se nome1>nome2

– getKey(v) -> s
	•Post: v=(nome, partite, punti, reti fatte, reti subite) AND s=nome

–aggiornaReti(i, r1, r2) ->
	•Pre: i(nome, partite, punti, reti fatte, reti subite)
	•Post: i=(nome, partite, punti, reti fatte + r1, reti subite + r2)

–aggiungiPunti(i1, i2, p1, p2) ->
	•Pre: i1=(nome1, partite1, punti1, reti_fatte1,reti_subite1) AND i2=(nome2, partite2, punti2, reti_fate2, reti_subite2)
	•Post: i2=(nome1, partite1, (punti1 + p1), reti_fatte1,reti_subite1) AND i2=(nome2, partite2, (punti2 + p2), reti_fate2, reti_subite2)

–incrementaPartite(i) ->
	•Pre: i=(nome, partite, punti, reti fatte, reti subite)
	•Post: i=(nome, partite', punti, reti fatte, reti subite)

–compare(i1, i2) -> b
	•
*/

typedef struct squadra *item;

item newSquadra(char nom[], int par, int pun, int r_f, int r_s);

item inputSquadra();

void output_Squadra(item v);

int cmpItem(item a, item b);

void aggiornaReti(item *s1, int reti1, int reti2);

void incrementaPartite(item *s1);

void aggiungiPunti(item *s1, item *s2, int puntis1, int puntis2);

char *getKey(item value);

int compare(item a, item b);