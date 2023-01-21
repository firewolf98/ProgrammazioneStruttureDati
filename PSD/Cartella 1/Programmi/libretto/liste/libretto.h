/*
SPECIFICA ADT LIBRETTO:

	-TIPO:
		SINTATTICA:
			-TIPO DI RIFERIMENTO: Libretto;
			-TIPI USATI: item, list, boolean, integer, string;
			
		SEMANTICA:
			Libretto è l'insieme delle quadruple:
				-COGNOME
				-NOME
				-MATRICOLA
				-ESAMI
			Libretto contiene anche un elemento nil che rappresenta il libretto vuoto;
			
	-OPERATORI:
		SINTATTICA:
			-newLib(integer, stringa, stringa)->libretto;
			-addExam(libretto, esame)-> libretto;
			-searchExam(libretto, corso)-> boolean;
			-outputLib(libretto)->libretto;
		-SEMANTICA:
			-newLib(matr, cognome, nome)->lib a;
				-POST: a = <matricola, cognome, nome, / >;
			-addExam(lib a, esame es)-> lib a', boolean c;
				-PRE: lib = <matr, cognome, nome, esami> AND per ogni i es != esami[i];
				-POST: lib = <matr, cogn, nome, esame U {es}>;
			-searchExam(lib a, corso b)-> esame es;
				-PRE: lib = <matr, cognome, nome, esame>
				-POST: es appartiene ad esami AND getItem(es)=corso;
			-outputLibretto(lib a)->lib a';
				PRE: a != nil;
*/

typedef struct libretto *lib;

lib newLib ( char [], char [], int ); //alloca un libretto con il nome, il cognome e la matricola dello studente, l'inseme degli esami è vuoto
int searchExam ( lib, char [] );//restituisce 1 se l'esame è gia presente, altrimenti restituisce 0
int addExam ( lib, item );//aggiunge un esame al libretto e restituisce 1 se l'operazione è andata a buon fine, altrimenti -1
int outputLib ( lib );//stampa il libretto
