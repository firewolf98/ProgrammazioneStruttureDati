#include <stdio.h>
#include <stdlib.h>
#include "ordinamento.h"
#include "file_array.h"
#include "intlib.h"
#define M 20

int run_test_case (char *TC_ID,int n);

int main(int argc,char *argv[])
{
	FILE *test_suite,*result;
	char TC_ID[M];
	int n,pass;
	if(argc<3)
	{
		printf("Nomi dei file mancanti\n");
		exit(1);
	}
	test_suite=fopen(argv[1],"r");
	result=fopen(argv[2],"w");
	if(test_suite==NULL || result==NULL)
	{
		printf("Errore in apertura dei file\n");
		exit(1);
	}
	while(fscanf(test_suite,"%s%d",TC_ID,&n)==2)
	{
		pass=run_test_case(TC_ID,n);
		fprintf(result,"%s",TC_ID);
		if(pass==1)
			fprintf(result,"PASS\n");
		else
			fprintf(result,"FAIL\n");
	}
	fclose(test_suite);
	fclose(result);
}

int run_test_case(char *TC_ID,int n)
{
	char fname_input[M], fname_oracle[M],fname_output[M];
	sprintf(fname_input, "%s_input.txt", TC_ID);
	sprintf(fname_oracle, "%s_oracle.txt", TC_ID);
	sprintf(fname_output,"%s_output.txt", TC_ID);
	int *a=(int *)calloc(n,sizeof(int));
	if(a==NULL)
	{
		printf("Memoria insufficiente\n");
		return -1;
	}
	finput_array(fname_input,a,n);
	Insertionsort(a,n);
	foutput_array(fname_output,a,n);
	int *oracle=calloc(n,sizeof(int));
	if(oracle==NULL)
	{
		printf("Memoria insufficiente\n");
		return -1;
	}
	finput_array(fname_oracle,oracle,n);
	return confronta_array(a,oracle,n);
}

