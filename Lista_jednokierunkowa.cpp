#include <iostream>
using namespace std;
struct lista
{
	int value;
	lista *ptr;
};

void addFront(lista *&start)
{
	lista* p;
	p = start;
	for (int i = 0; i < 10; i++)
	{
		p = new lista;
		p->value = i;
		p->ptr = start;
		start = p;

	}
}

void printList(lista*& start)
{
	lista* p;
	p = start;
	while (p)
	{
		cout << p->value << " ";
		p = p->ptr;
	}
}

void deleteList(lista*& start)
{
	lista *p;

	while (start)
	{
		p = start;
		start = start->ptr;
		delete p;
	}
}

int countList(lista*& start)
{
	int counter = 0;
	lista* p = start;
	p = start;
	
	while(p)
	{
		counter++;
		p = p->ptr; //przechodzenie po liscie
	}
	return counter;
}

void deleteFront(lista*& start)
{
	lista* p;
	p = start;

	if (p)
	{
		start = start->ptr;
		delete p;
	}

	else
	{
		cout << "Lista pusta";
	}
}

void addBack(lista*& start)
{
	lista* p,*n;
	p = start;
	if (p)
	{
		while (p->ptr) p = p->ptr;
		n = new lista;
		n->value = 99;
		n->ptr = nullptr;
		p->ptr = n;
	}

	else
	{
		cout << "\nLista pusta";
	}
}

void deleteBack(lista*& start)
{
	lista* p, * n;
	p = start;

	if (p)
	{
		if (p->ptr)
		{
			//szukamy nastepnego elementu
			while (p->ptr->ptr) p = p->ptr;
			delete p->ptr;
			p->ptr = nullptr;
		}

		else
		{
			delete p;
			start = nullptr;
		}
	}

	else
	{

	}

}

int main()
{
	lista *start; //wskaznik pusty
	start = nullptr;

	addFront(start);
	printList(start);
	cout<<countList(start);
	deleteList(start);
	return 0;
}
