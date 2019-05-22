#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxd 100
int main(int argc, char *argv[]){
FILE *plik;
char linia [maxd], slowo[maxd], nazwa[30];
//printf ("Podaj nazwe pliku: ");
//gets (argv[2]); // pobiera nazwê pliku
if ((plik = fopen ( argv[1], "r" )) == NULL){
 fprintf (stderr,"Blad otwarcia pliku!!! ");
 exit(1);
}

printf ("Podaj szukane slowo: ");
//gets(slowo); // pobiera szukane s³owo z klawiatury
while (fgets (linia, maxd, plik) != NULL){
if (strstr (linia, argv[2]) != NULL)
 fputs (linia, stdout);
}
fclose (plik);
return 0;
}
