#include <stdio.h>
int main() 
{
int mat[3][3],i,j,temp;
temp=0;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++) {
	mat[i][j]=0;
	printf("Inserisci il valore\n");
	scanf("%d",&mat[i][j]); }
				for(i=0;i<3;i++) {
				for(j=0;j<3;j++) {
				printf("%d\t",mat[i][j]); }
				printf("\n"); }


		for(i=0;i<3;i++)
		for(j=0;j<3;j++) {
			if((i>=j)&&(i!=j)) {
			temp=mat[i][j];
			mat[i][j]=mat[j][i];
			mat[j][i]=temp; }
			}
printf("\n");
				
				for(i=0;i<3;i++) {
				for(j=0;j<3;j++) {
				printf("%d\t",mat[i][j]); }
				printf("\n"); }
 }
