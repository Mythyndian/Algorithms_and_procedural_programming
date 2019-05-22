// Pliki, argumenty wywolania programu
#include <stdio.h>
#include <stdlib.h>

void linia(int);
 
int main(int argc, char *argv[]){
  linia(1);
/*(1) Sprawdziæ dzialanie programu*/

//Przyklad 1////////////////////////////////////////////

int i;
printf("Parametry programu:\n"); 
for (i=0;i<argc;i++)
  printf("%s\n", argv[i]);

//Przyklad 2  //////////////////////////////////////////

/*while(argc>0){
   printf("%s\n",*argv);
   argc--;
   argv++;
} */

//Przyklad 3////////////////////////////////////////////

//while( *++argv !=NULL)
 // printf("%s\n",*argv);    //nie drukuje nazwy programu!
 
/////////////////////////////////////////////////////////
linia(2);

FILE *plik1, *plik2;
    
if(argc!=3){
  fprintf(stderr, "\nWywoluj z parametrami. %s 1:nazwa pliku 1, 2:nazwa pliku 2\n\n", argv[0]);           
  exit(1);
}


if ((plik1=fopen(argv[1],"a"))==NULL) { 
    fprintf(stdout,"%Nie mo¿na otworzyc pliku: %s", argv[1]);
    exit(0);
    }

    printf("\nPlik %s otwarty do aktualizacji.\n", argv[1]); 

//Otworzyæ drugi plik
//Dopisaæ zawartoœæ drugiego pliku do pierwszego
char c;
if ((plik2=fopen(argv[2],"r"))==NULL) { 
    fprintf(stdout,"%Nie mo¿na otworzyc pliku: %s", argv[2]);
    exit(0);
    }
		while((c = fgetc(plik2))!=EOF) 
			fputc(c,plik1);
if(fclose(plik1)!=0)
    fprintf(stderr, "Blad zamkniecia pliku %s.\n", *(argv+1));           
//Zamkn¹æ drugi plik
if(fclose(plik2)!=0)
    fprintf(stderr, "Blad zamkniecia pliku %s.\n", *(argv+2));
return 0;
}

void linia(int k){
if (k>0) printf("\n\n______________ %d ________________\n\n",k);
else printf("\n\n___________________________________\n\n");
}
