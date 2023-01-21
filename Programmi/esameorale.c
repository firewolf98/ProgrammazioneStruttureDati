#include <stdio.h>
#include <stdlib.h>
int main(void) {
char *vect[2]={"Luca","Esposito"};
printf("%c, %p",vect[1][1],&vect[1][1]);
}
