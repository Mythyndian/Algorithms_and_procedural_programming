#include <iostream>
void swap(int* a, int* b);
void BubbleSort(int T[], int n);
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

	BubbleSort(T, 10);

	cout << "T = { ";
	for (int i = 0; i < 10; i++)
	{
		cout << T[i] << " ";
	}
	cout << "}";

	return 0;
}

void BubbleSort(int T[], int n)
{
	int it = 0;
 
	while (it < n - 1)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (T[j] > T[j + 1])
				swap(&T[j], &T[j + 1]);
		}
		it++;
	}
}

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}