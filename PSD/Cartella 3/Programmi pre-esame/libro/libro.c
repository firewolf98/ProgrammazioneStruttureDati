#include "libro.h"

Libro CreaLibro(char *aut,char *tit, char *ed,int anno)
{
	libro l;
	strcpy(l.autore,aut);
	strcpy(l.titolo,tit);
	strcpy(l.editore,ed);
	l.anno=an;
	return l;
}

char *autore(libro l)
{
	char *aut;
	aut=calloc(26,sizeof(char));
	strcpy(aut,l.autore);
	return aut;
}

char *titolo(libro l)
{
	char *tit;
	tit=calloc(53,sizeof(char));
	strcpy(tit,l.titolo);
	return tit;
}

char *editore(libro l)
{
	char *ed;
	ed=calloc(26,sizeof(char));
	strcpy(ed,l.editore);
	return ed;
}

int anno(libro l)
{
	return l.anno;
}
