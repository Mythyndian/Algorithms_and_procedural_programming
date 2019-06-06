#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int main(void)
{
FILE * plik;
int p_counter,line_counter;
plik = fopen("plik.txt","r");

	if(plik == NULL)
	{
		printf("Plik nie zostal otwarty");
		exit(0);
	}
	
	while(!feof(plik))
	{
		char c = fgetc(plik);
		if(c == 'p')
		{
			p_counter++;
			printf("P w linii -> %d",line_counter);
		}
			
		if(c == '\n')
			line_counter++;
	}
	
	printf("Ilosc p: %d",p_counter);
	printf("Ilosc nowwych linii %d",line_counter);
	fclose(plik);
	return 0;
}

