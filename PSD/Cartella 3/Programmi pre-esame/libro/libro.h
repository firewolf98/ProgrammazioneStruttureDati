/*
	-Specifica sintattica:
		Tipi:
			-Tipo di riferimento: libro
			-Tipi usati: stringa,intero
		Operatori
			-CreaLibro(stringa,stringa,stringa,intero)->libro
			-Autore(libro)->stringa
			-Editore(libro)->stringa
			-Anno(libro)->intero
	-Specifica semantica:
		Tipi:
			-Il tipo libro è l'insieme delle quadruple(Autore,Titolo,Editore,Anno),dove:
				Autore,Titolo e Editore sono stringhe e Anno è intero
		Operatori:
			-CreaLibro(aut,tit,ed,an)=lb
				post: lb=(aut,tit,ed,an)
			-Autore(lb)=aut
				post: lb=(aut,tit,ed,an)
			-Titolo(lb)=tit
				post: lb=(aut,tit,ed,an)
			-Editore(lb)=ed
				post: lb=(aut,tit,ed,an)
			-Anno(lb)=an
				post: lb=(aut,tit,ed,an)
*/

typedef struct lib {
	char autore[26];
	char titolo[53];
	char editore[26];
	int anno;
}; libro;

libro CreaLibro(char *aut,char *tit,char *ed,int anno);
char *autore(libro l);
char *titolo(libro l);
char *editore(libro l);
int anno(libro l);
