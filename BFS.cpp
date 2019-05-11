#include <iostream>

struct listEl
{
	listEl* next;
	int value;
};

int n;
listEl** M;
bool* visited;

void BFS(int k)
{
	listEl* p, * q, * head, * tail; //head , tail , q do obslugi kolejki

	q = new listEl; //k do kolejki
	q->next = NULL;
	q->value = k;
	head = tail = q;

	visited[k] = true;

	while (head)
	{
		k = head->value;
		if (!head) tail = NULL;
		delete q;

		cout << k << endl;

		for (p = M[k]; p; p = p->next)
		{
			if (!visited[p->value])
			{
				q = new listEl;
				q->next = NULL;
				q->value = p->value;
				if (!tail) head = q;
				else tail->next = q;
				tail = q;
				visited[p->value] = true;
			}
		}
	}
}

int main()
{
	int m, i, n1, n2;
	listEl* p, * r;
	cin >> n >> m;

	M = new listEl * [n];
	visited = new bool[n];

	{
		cin >> n1 >> n2;    // Wierzchołek startowy i końcowy krawędzi
		p = new listEl;    // Tworzymy nowy element
		p->value = n2;          // Numerujemy go jako v2
		p->next = M[n1];    // Dodajemy go na początek listy A[v1]
		M[n1] = p;
	}

	cout << endl;

	// Przechodzimy graf wszerz

	BFS(0);

	// Usuwamy tablicę list sąsiedztwa

	for (i = 0; i < n; i++)
	{
		p = M[i];
		while (p)
		{
			r = p;
			p = p->next;
			delete r;
		}
	}
	delete[] M;
	delete[] visited;

	cout << endl;
