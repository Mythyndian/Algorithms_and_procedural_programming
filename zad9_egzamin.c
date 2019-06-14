#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **alokuj_tab_str(FILE * file);
int main()
{
    FILE * plik;
    if((plik = fopen("lec.txt","r")) == NULL)
        printf("Nie udalo sie otworzyc pliku :X\n");
    char **tab;
    tab = alokuj_tab_str(plik);
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < sizeof(tab[i]); i++)
            printf("%c",tab[i][j]);
    getchar();
    return 0;
    }

}
char **alokuj_tab_str(FILE * file)
{

/*zliczanie liczby znakow w wierszu */
    char table[26][100];
    char *str[26];
    for(int i = 0; i < 26; i++)
    {
       str[i] = fgets(table[0],100,file);
    }
/*Alokacja pamiecie dla napisow*/
    char **lines = (char **) malloc(26 * sizeof(char *));

    for(int i = 0; i < 26; i++)
        lines[i] = (char *) malloc(strlen(str[i])* sizeof(char)+1);
return lines;
}
