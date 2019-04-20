#include <stdio.h>
void PrintArray(int T[], int n);
void swap(int *x, int *y);
void InsertionSort(int T[], int n);
int main() {
  int T[] = {9,5,1,4,7,2,3};
InsertionSort(T,7);
PrintArray(T,7);

  return 0;
}

void InsertionSort(int T[], int n){
  int i, key, j;
      for (i = 1; i < n; i++) {
          key = T[i];
          j = i - 1;

          /* Move elements of arr[0..i-1], that are
            greater than key, to one position ahead
            of their current position */
          while (j >= 0 && T[j] > key) {
              T[j + 1] = T[j];
              j = j - 1;
          }
          T[j + 1] = key;
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
