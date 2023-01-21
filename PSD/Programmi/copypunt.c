#include <stdio.h>
#include <string.h>
void copy1(char*,char*);
void copy2(char*,char*);


int main(void) {
char string1[10],*string2="Hello", string3[10], *string4="Good Bye";
copy1(string1,string2);
printf("string1= %s\n",string1);
copy2(string3,string4);
printf("string3= %s\n",string3);
return 0; }


void copy1(char *string1, char *string2) {
strcpy(string1,string2); }

void copy2(char *string3, char *string4) {
*strcpy(string3,string4); }
