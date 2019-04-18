#include <stdio.h>
#define M 5
void Scal(int T1[],int n1, int T2[], int n2, int T3[]);
int main(void){
	int T1 = {1,2,3,4,5};
	int T2 = {3,4,5,6,7};
	int T3[M+M] = {0};
	Scal(T1,M,T2,M,T3);
}

void Scal(int T1[], int n1, int T2[], int n2, int T3[]){
	int *current;
	current = &T3[0];
		for(int i = 0; i < M; i++){
			if(T1[i] > T2[i]){
				*current = T2[i];
				*(current+1) = T1[i];
				current+=2;
			}
				
			else 
				if(T1[i] == T2[i]){
				*current = T1[i];
				*(current+1) = T2[i];
				current+=2;
				}
				
			else{
				*current = T1[i];
				*(current+1) = T2[i];
				current+=2;
			}
				
		}

	}
	

