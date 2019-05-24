// Pliki
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void linia(int);

int main(void){
    linia(1);
/*(1) Sprawdzić dzialanie programu*/

FILE *plik;

 if ((plik=fopen("DANE.TXT","w"))==NULL) {
      puts("Blad otwarcia pliku!");
      exit(EXIT_FAILURE);
  }

  int i;
  srand((unsigned int)time(0));
  for (i=0;i<20;i++)
     fprintf(plik,"%d ", rand()%100);

  fclose(plik);

  printf("Wylosowane liczby zapisano w pliku DANE.TXT\n");

linia(2);
/*(2) Napisac instrukcje programu, ktore spowoduja odczytanie
  liczb z pliku DANE.TXT i wyswietlenie ich na ekranie*/
 if ((plik=fopen("DANE.TXT","r"))==NULL) {
      puts("Blad otwarcia pliku!");
      exit(EXIT_FAILURE);
  }
  char ch;
   while((ch = fgetc(plik)) != EOF)
      printf("%c", ch);

return 0;
}



void linia(int k){
if (k>0) printf("\n\n______________ %d ________________\n\n",k);
else printf("\n\n___________________________________\n\n");
}
