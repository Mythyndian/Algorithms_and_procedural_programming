#include <stdio.h>
void SelectionSort(int T[], int n);
int main(){
	int T[] = {9,5,1,4,7,2,3};
	SelectionSort(T,sizeof(T)/4);
	PrintArray(T,sizeof(T)/4);
}

void SelectionSort(int T[], int n){
	int index_min,i,j;

for(i = 0; i < n-1; i++){//sterowanie iteracjami
	index_min = i;
			for(j = i+1;j < n;j++){//znajdowanie indexu najmniejszego elementu
			if(T[j-1] > T[j]){
				index_min = j;
			
			}
	
			swap(&T[i],&T[index_min]);//zamiana (i,index_min)

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
