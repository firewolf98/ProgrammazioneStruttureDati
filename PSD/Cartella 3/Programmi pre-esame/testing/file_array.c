#include <stdio.h>

/*      void finput_array(char *file_name,int a[],int n)
	{
		file *fd=fopen(file_name,"r");
		if(fd==NULL)
			printf("Errore in apertura del file %s\n",file_name);
		else
		{
			for(int i=0;i<n;i++)
				fscanf(fd,"%d",&a[i]);
			fclose(fd);
		}
	}
*/

void finput_array(char *file_name,int a[],int n)
{
	FILE *fd=fopen(file_name,"r");
	if(fd==NULL)
		printf("Errore in apertura del file %s\n",file_name);
	else
	{
		int i=0;
		fscanf(fd,"%d",&a[i]);
		while(i<n && !feof(fd))
		{
			i++;
			fscanf(fd,"%d",&a[i]);
		}
		fclose(fd);
		if(i<n)
			n=i;
	}
}

void foutput_array(char *file_name,int a[],int n)
{
	int i;
	FILE *fd;
	fd=fopen(file_name,"w");
	if(fd==NULL)
		printf("Errore in apertura del file %s\n",file_name);
	else 
	{
		for(i=0;i<n;i++)
			fprintf(fd,"%d\n",a[i]);
		fclose(fd);
	}
}
