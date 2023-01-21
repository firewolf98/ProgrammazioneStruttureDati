#include "../../librerie/ordinamento.h"
#include "../../librerie/intlib.h"
#include "../../librerie/filelib.h"
#include <stdio.h>
#include <stdlib.h>

int controllo (int);

int main(int argc, char **argv){

int *array, *output, dim, r, control;
FILE *input, *oracolo, *out;
//effettuo il controllo dell'input
	control=controllo(argc);
		if(control)
			printf("Numero di argomenti sbagliato!\n");
//apro il file che contiene gli elementi di input
	input=fopen(argv[1], "r");
//apro il file che contiene l'output corretto	
	oracolo=fopen(argv[2], "r");
//apro il file che conterrà l'output effettivo	
	out=fopen(argv[3], "w");
//conto quanti elementi ci sono all'interno del file input
	dim=conta_in_file(input);
//faccio un rewind del file input per posizionarmi all'inizio di esso
	rewind(input);
//alloco l'array che conterrà l'input	
	array=calloc(dim,sizeof(int));
//registro nell'array gli elementi del file di input
	outfile(input, array, dim);
//ordino l'array "array"
	Insertionsort(array,dim);
//alloco l'array che conterrà l'oracolo
	output=calloc(dim, sizeof(int));
//registro nell'array "output" gli elementi contenuti nel file "oracolo"
	outfile(oracolo, output, dim);
//cofronto l'oracolo con l'array di input
	r=confronta_array(output, array, dim);
//controllo l'esito del confronto
if(!r){
//scrivo nel file di output il risultato del riordino dell'array
	infile(out, array, dim);
//esito positivo: scrivo nel file PASS e lo stampo a video
		printf("PASS\n");		
			fprintf(out, "\tPASS");
}
if(r){
	infile(out, array, dim);
//esito negativo: scrivo nel file FAIL e lo stampo a video
			printf("FAIL\n");
				fprintf(out, "\tFAIL");
}

	free(array);
	free(output);
	fclose(input);
	fclose(oracolo);
	fclose(out);
}

int controllo (int argc )
{
if (argc!= 4) return 1;
return 0;
}
