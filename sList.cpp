#include <iostream>
//int size(sListEl * head);
//void print(sListEl * head);
using namespace std;

struct sListEl{
	int data;
	sListEl * next;
};

int main(){
	
return 0;
}

int size(sListEl * head){
	int c = 0;
	while(head){ //analogiczne do wyrazenia (head != NULL)
		c++; //zwieksz licznik
		head = head->next; //przejdz dalej
	}
return c;
}

void print(sListEl * head){
	while(head){
		cout<<head->data<<endl;
		head = head->next;
	}
}

