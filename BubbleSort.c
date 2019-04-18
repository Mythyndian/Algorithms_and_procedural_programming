#include <stdio.h>
void PrintArray(int T[], int n);
void swap(int *x, int *y);
void BubbleSort(int T[], int n);
int main(){
    int T[] = {9,5,1,4,7,2,3};
    BubbleSort(T,7);
    PrintArray(T,7);

}

void BubbleSort(int T[], int n){
    int i,j;
    for(j = 0; j < n-1; j++){
            for(i = 0; i < n-j-1; i++){
                if(T[i] > T[i+1])
                    swap(&T[i],&T[i+1]);
    }
    }

}

void swap(int *x, int *y){
	int temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

void PrintArray(int T[], int n){

	for(int i = 0;i < n;i++){
		printf("%d ",T[i]);
		
	}
}