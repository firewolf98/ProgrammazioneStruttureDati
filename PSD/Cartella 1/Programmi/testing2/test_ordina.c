#include "../../librerie/ordinamento.h"
#include "../../librerie/intlib.h"
#include "../../librerie/filelib.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 25


void controllo ( int );
int compara ( char [], char [], char [] );

int main (int argc, char **argv)
{
	FILE *input, *output;
	char fname_input[MAX], fname_oracolo[MAX],fname_output[MAX], tc_id[MAX];
	int control=0;

	controllo(argc);
	input=fopen(argv[1], "r");
	output=fopen(argv[2], "w");
		
	while(fscanf(input, "%s", tc_id)!=EOF){
		sprintf(fname_input, "%s_input.txt", tc_id);
		sprintf(fname_oracolo, "%s_oracolo.txt", tc_id);
		sprintf(fname_output,"%s_output.txt", tc_id);
		control=compara (fname_input, fname_oracolo, fname_output);
		if(!control){
			printf("%s\tPASS\n", tc_id);
			fprintf(output, "%s\tPASS\n", tc_id);	
		}
		if (control){
			printf("%s\tFAIL\n", tc_id);
			fprintf(output, "%s\tFAIL\n", tc_id);
		}
	}
	fclose(input);
	fclose(output);
	
	return 0;
}


void controllo (int argc )
{
	if (argc!= 3) {
		exit(1);
	}
	else {	
		printf("Argomenti validi\n");
	}
	
}


int compara ( char fname_input[], char fname_oracolo[], char fname_output[] )
{
	FILE *input, *oracolo, *out;
	int *array, *output, dim, result, i, j;

	input=fopen(fname_input, "r");
	oracolo=fopen(fname_oracolo, "r");
	dim=conta_in_file(input);
	rewind(input);

	array=calloc(dim,sizeof(int));
	output=calloc(dim,sizeof(int));

	outfile(input, array, dim);
	Insertionsort(array, dim);
	outfile(oracolo, output, dim);
	result=confronta_array(array, output, dim);
		if(result){
			out=fopen(fname_output,"w");
			infile(out, array, dim);
			fclose(out);
		}
	
	free(array);
	free(output);
	fclose(input);
	fclose(oracolo);

	return result;
}
