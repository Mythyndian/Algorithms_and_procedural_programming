#include <stdio.h>
void SelectionSort(int T[], int n);
int main(){
	int T[] = {9,5,1,4,7,2,3};
	SelectionSort(T,sizeof(T)/4);
	PrintArray(T,sizeof(T)/4);
}

void SelectionSort(int T[], int n){
	int index_min = 0;
	int k = 0;
	while(k < 7){
		for(int i = 1;i < n;i++){
			if(T[index_min] > T[i]){
				index_min = i;
			}
		}
	if(k != index_min)
		swap(&T[k],&T[index_min]);
	k++;
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
