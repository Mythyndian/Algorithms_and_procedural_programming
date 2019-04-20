#include <stdio.h>
#define N 7
void Merge(int T[], int Copy[], int leftIndex, int middleIndex, int rightIndex);
void PrintArray(int T[], int n);
void MergeSort(int T[], int leftindex, int rightindex);
void swap(int *x, int *y);
int main(){
    int T[] = {9,5,1,4,7,2,3};
    
    MergeSort(T,0,N-1);
    return 0;
}

void MergeSort(int T[], int leftindex, int rightindex){
    if(leftindex < rightindex){
        int middle = (leftindex + rightindex)/2;
        MergeSort(T,leftindex,middle);
        MergeSort(T,middle + 1, rightindex);
       merge(T,leftindex,middle,rightindex);    
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

void merge(int T[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = T[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = T[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
           T[k] = L[i]; 
            i++; 
        } 
        else
        { 
            T[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        T[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        T[k] = R[j]; 
        j++; 
        k++; 
    } 
} 