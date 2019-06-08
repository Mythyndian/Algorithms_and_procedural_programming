#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
typedef struct ulamek
{
    unsigned licznik;
    unsigned mianownik;
}ULAMEK;

int main()
{
    ULAMEK magazine[N];
    ULAMEK result[N];
    srand(time(NULL));
    FILE * plik;
    if((plik = fopen("ULAMKI.TXT","w+"))==NULL)
        printf("Nie udalo sie otworzyc pliku :X");
    for(int i = 0; i < N; i++)
    {
        magazine[i].licznik = rand()%10 +1;
        magazine[i].mianownik = rand()%10 +1;
    }

    for(int i = 0; i < N; i++)
    {
        printf("%u/%u\n",magazine[i].licznik,magazine[i].mianownik);
    }
    printf("-------------------------------------------------------------\n");
    for(int i = 0; i < N; i++)
    {
        fprintf(plik,"%u/%u\n",magazine[i].licznik,magazine[i].mianownik);
    }

    rewind(plik);

    for(int i = 0; i < N; i++)
    {
        fscanf(plik,"%u",&result[i].licznik);
        fscanf(plik,"%u",&result[i].mianownik);
    }

    for(int i = 0; i < N; i++)
    {
        printf("%u/%u\n",result[i].licznik,result[i].mianownik);
    }

}
