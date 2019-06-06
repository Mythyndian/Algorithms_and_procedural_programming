#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    double * magazine;
    magazine = (double*) malloc(20 * sizeof(double));
    if(magazine == NULL)
        printf("Nie udalo sie zainicjalizowac pamieci :X");
    srand(time(NULL));
    FILE * plik;
    double liczby[20];
    if((plik = fopen("DANE.BIN","w+")) == NULL)
    {
        printf("Nie udalo sie otworzyc pliku :X");
        exit(0);
    }

    for(int i = 0; i < 20; i++)
    {
        liczby[i] = rand()%10;
    }

    for(int i = 0; i < 20; i++)
    {
        printf("%.2f\n",liczby[i]);
    }

    fwrite(liczby,sizeof(liczby),1,plik);

    printf("------------------------------------------------\n");

    fread(magazine,sizeof(liczby),1,plik);

    for(int i = 0; i < 20; i++)
    {
        printf("%hf\n",magazine[i]);
    }

    fclose(plik);

    return 0;
}
