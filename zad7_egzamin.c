#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define W 8
#define K 12
void uzupelnij_wyswietl(char (*tab)[K]);
int main (void)
{
	char tablica[W][K];
	uzupelnij_wyswietl(tablica);
	return 0;
}

void uzupelnij_wyswietl(char (*tab)[K])
{
	srand(time(NULL));
	
	for(int i = 0; i < W; i++)
	{
		for(int j = 0; j < K; j++)
		{
			if(rand()%2 == 0)
				tab[i][j] = rand()%25 + 65;//duze 65-90
			else
				tab[i][j] = rand()%25 + 97; //male 97-122
		}	
	}
	
	for(int i = 0; i < W; i++)
	{
		for(int j = 0; j < K; j++)
			printf("%c ",tab[i][j]);
		printf("\n\n");
	}
}
