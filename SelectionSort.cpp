#include <iostream>
void SelectionSort(int T[], int n);
void swap(int * a, int * b);
using namespace std;

int main()
{
	int T[] = { 9,8,7,6,5,4,3,2,1,0 };
	cout << "T = { ";
	for (int i = 0; i < 10; i++)
	{
		cout << T[i] << " ";
	}
	cout << "}\n";
	
	SelectionSort(T, 10);

	cout << "T = { ";
	for (int i = 0; i < 10; i++)
	{
		cout << T[i] << " ";
	}
	cout << "}";
	
	return 0;
}

void SelectionSort(int T[], int n)
{
	int index_min;
	for (int i = 0; i < n-1; i++)
	{
		index_min = i;
		for (int j =i + 1; j < n; j++)
		{
			if (T[j] < T[index_min])
				index_min = j;
		}
		swap(&T[i], &T[index_min]);
	}
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}