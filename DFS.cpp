#include <iostream>

using namespace std;

struct listEl
{
	listEl* next;
	int value;
};

listEl** M; //macierz list
bool* visited; //tablica przechowujaca informacje o tym czy dany wezel zostal odwiedzony

void DFS(int k)
{
	listEl* S, * p, * r;
	p = new listEl; 
	p->value = k;
	p->next = NULL;
	S = p; //wierzcholek startowy trafia na stos

	visited[k] = true;

	while (S) //kiedy cos jest na stosie
	{
		k = S->value;							//odczytujemy wierzcholek ze stosu
		S = S->next;							//usuwamy wierzcholek ze stosu
		cout << k << endl;						//aktualnie przetwarzany wierzcholek
	}

	//przechodzimy przez liste sasiedztwa
	for (p = M[k]; p; p = p->next)
	{
		if (!visited[p->value])
		{
			r = new listEl;
			r->value = p->value;
			r->next = S;
			S = r;
			visited[p->value] = true;
		}
	}
}

int main()
{
	int n, n1, n2, m, i;
	listEl* p, * r;
	cout << "Podaj liczbe wierzcholkow" << endl;	// Czytamy liczbę wierzchołków i krawędzi
	cin >> n;                
	cout << "Podaj liczbe krawedzi: " << endl;
	cin >> m;
	listEl *[n]
	visited = new bool[n];

	//wypelnienie macierzy pustymi listami

	for (i = 0; i < n; i++)
	{
		M[i] = NULL;
		visited[i] = false;
	}
	
	//Definicje krawedzi

	for (int i = 0; i < m; i++)
	{
		cin >> n1 >> n2;
		p = new listEl;
		p->value = n2;
		p->next = M[n1];
		M[n1] = p;
	}

	DFS(0); //wywolanie przeszukiwania
	
	for (i = 0; i < n; i++)
	{
		p = M[i];
		while (p)
		{
			r = p;
			p = p->next;
		}
	}

	delete[] M;
	delete[] visited;


	return 0;
}	
