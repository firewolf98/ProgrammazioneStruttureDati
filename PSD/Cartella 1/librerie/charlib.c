#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scambia( char x[], char y[] )
{
	char temp[10];
	strcpy(temp,x);
	strcpy(x,y);
	strcpy(y,temp);
}
