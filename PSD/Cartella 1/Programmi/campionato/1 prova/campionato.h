/*
SPECIFICA ADT CAMPIONATO

	-TIPO:
		SINTATTICA:
			TIPO DI RIFERIMENTO: campionato
			
		SEMANTICA:
			campionato è la coppia formata da: <nome campionato, lista squadre>
			
	-OPERATORI:
		SINTATTICA:
			-newCampionato()-> campionato
			-addSquadra(campionato)-> campionato
			-searchSquadra(campionato, string)-> squadra
			-outputCampionato(campionato)->campionato
		SEMANTICA:
			-newCampionato()-> campionato c
				POST: c = <NOME CAMPIONATO, insieme vuoto>
			-addSquadra(campionato c)-> campionato c'
				-POST: c = <C1, C2, .., Cn> AND item b != NULL AND c' = <C1, C2,..,Cn> U <b>
			-searchSquadra(campionato c, string a)-> squadra b
				POST: se a è il nome della squadra "v" appartenente a c allora b = v
			-outputCampionato(campionato c)-> campionato c
				POST: stampa a video il campionato c
*/

typedef struct campionato *Campionato;

struct campionato *newCampionato( char []); //alloca un campionato e riempie il campo nome con il nome del campionato
item searchSquadra(Campionato, char[]); //cerca una squadra all'interno del campionato
int addSquadra(Campionato); //inserisce una squadra in ordine alfabetico
int outputCampionato(Campionato); //stampa un campionato a video
