#include <stdio.h>
#include <stdlib.h>
#define P1 4
#define P2 8
void scal(int *T1, int n1, int *T2, int n2, int *T3, int rozmiar);
int main() {
    int *t1 = (int *) malloc(P1*sizeof(int));
    t1[0] = 0; t1[1] = 5;  t1[2] = 9; t1[3] = 16;
    int *t2 = (int *) malloc(P2*sizeof(int));
    t2[0] = 1; t2[1] = 3; t2[2] = 4; t2[3] = 15; t2[4] = 17; t2[5] = 19; t2[6]=21; t2[7]=28;
    int rozmiar_trzeciej = P1+P2;
    int *t3 = (int *) malloc(rozmiar_trzeciej*sizeof(int));
    scal(t1,P1,t2,P2,t3,P1+P2);
    for(int i=0; i<rozmiar_trzeciej; i++)
        printf("%d\n",t3[i]);
    return 0;
}
void scal(int *T1, int n1, int *T2, int n2, int *T3, int rozmiar){
    int *current;
    current = &T3[0];
    int rozmiar_roznica;
    if(n1==n2) {
        for (int i = 0; i < rozmiar; i++) {
            if (T1[i] > T2[i]) {
                *current = T2[i];
                *(current + 1) = T1[i];
                current += 2;
            } else if (T1[i] == T2[i]) {
                *current = T1[i];
                *(current + 1) = T2[i];
                current += 2;
            } else {
                *current = T1[i];
                *(current + 1) = T2[i];
                current += 2;
            }
        }
    }
    else if(n1 >n2){
        int i;
        for (i = 0; i <n2; i++) {
            if (T1[i] > T2[i]) {
                *current = T2[i];
                *(current + 1) = T1[i];
                current += 2;
            } else if (T1[i] == T2[i]) {
                *current = T1[i];
                *(current + 1) = T2[i];
                current += 2;
            } else {
                *current = T1[i];
                *(current + 1) = T2[i];
                current += 2;
            }
        }
       // printf("\nWartosc %d\n",i);
       int j = 2*i;
        for(int k = i; k<n1;k++) { // ZACZYNAM OD MOMENTU WYJSCIA POZA OBSZAR TABLICY T2!!!!!
            T3[j] = T1[k];  // k to jest indeks w tym momencie pierwszej tablicy czyli 4 to do T3 co musze wpisac? - Podwojony indeks!
            j++;
        }
    }
    else{
        int i;
        for (i = 0; i < n1; i++) {
            if (T1[i] > T2[i]) {
                *current = T2[i];
                *(current + 1) = T1[i];
                current += 2;
            } else if (T1[i] == T2[i]) {
                *current = T1[i];
                *(current + 1) = T2[i];
                current += 2;
            } else {
                *current = T1[i];
                *(current + 1) = T2[i];
                current += 2;
            }
        }
        int j = 2 * i;
        for (int k = i; k < n2; k++) {
            T3[j] = T2[k];
            j++;
        }
    }
}