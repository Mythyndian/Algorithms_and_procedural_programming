#include <stdio.h>
#define N 7
void PrintArray(int T[], int n);
void swap(int *x, int *y);
int QuickSort(int T[], int left, int right);
int main(){
int T[] = {9,5,1,4,7,2,3};
if(sizeof(T)/4 == 0)
    return 0;
QuickSort(T,0,N-1);

}

int QuickSort(int T[], int left, int right){
    if(left >= right)
        return 0;

    int pivotValue = T[right];
    int border = left -1;
    int i = left;

    while(i < right){
        if(T[i] < pivotValue){
            border++;
            if(border!=i){
                swap(&T[i],&T[border]);
            }
        }
    i++;
    }

    border++;
    if(border != right)
        swap(&T[border],&T[right]);
    
    QuickSort(T,left, border - 1);
    QuickSort(T,border+1,right);
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