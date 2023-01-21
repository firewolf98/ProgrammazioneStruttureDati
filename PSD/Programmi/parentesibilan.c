#include <stdio.h>
#include <stdlib.h>
void research(FILE*,int*);
void print(int *);


int main(void) {
FILE *first;
int test=0;
first=fopen("uno","r");
research(first,&test);
print(&test); 
fclose(first);}


void research(FILE *first,int *test) {
int ch;
while((ch=getc(first))!=EOF) {
if(ch=='{')
(*test)++;
else if(ch=='}')
(*test)--;
} 
}


void print(int *test) {
if(*test==0)
printf("OK\n");
else if(*test>0)
printf("Raggiunta la fine del file prima di trovare }\n");
else 
printf("} senza corrispondente {\n"); }

