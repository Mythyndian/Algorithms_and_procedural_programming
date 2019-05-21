#include <iostream>
void InsertionSort(int T[], int n);
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

	InsertionSort(T, 10);

	cout << "T = { ";
	for (int i = 0; i < 10; i++)
	{
		cout << T[i] << " ";
	}
	cout << "}";
	return 0;
}

void InsertionSort(int T[], int n)
{
	int current,otherIndex;
	for (int i = 1; i < n; i++)
	{
		current = T[i];
		otherIndex = i;
		while (otherIndex > 0 && current < T[otherIndex - 1])
		{
			T[otherIndex] = T[otherIndex - 1];
			otherIndex--;
		}
		T[otherIndex] = current;
	}
}