// Pliki

#include <stdio.h>
#include <stdlib.h>

void linia(int);
 
int main(void){
linia(1);
/*(1) Napisaæ program, w którym wyœwietlana jest na  ekranie informacja o  
liczbie znaków i liczbie wierszy w pliku tekstowym. 
Nazwê pliku u¿ytkownik podaje z klawiatury.*/

FILE *plik;
char nazwa[40];

fprintf(stdout,"Podaj nazwe pliku\n");
fscanf(stdin, "%s",nazwa);

if ((plik=fopen(nazwa,"r"))==NULL){
 fprintf(stderr, "\nNie mozna otworzyc pliku do odczytu.\n\n");  
 exit(EXIT_FAILURE);
}

fprintf(stdout,"\nOK. Plik otwarty do odczytu, policz znaki i wiersze.\n");



if(fclose(plik)!=0)
  fprintf(stderr, "\nBlad zamkniecia pliku.\n");                   
 
linia(0);
return 0;
}

 

void linia(int k){
if (k>0) printf("\n\n______________ %d ________________\n\n",k);
else printf("\n\n___________________________________\n\n");
}
