#include <stdio.h>
#include <stdlib.h>
struct ListItem *AddItem(struct ListItem *list_ptr,int x);
void PrintList(struct ListItem *list_ptr);
struct ListItem
{
    int value;
    struct ListItem *next,*prev;
};

int main()
{
    /*Element poczatkowy*/
    struct ListItem *wlst = (struct ListItem *) malloc(sizeof(struct ListItem));
    wlst->value = 0;
    wlst->next = NULL;
    wlst->prev = NULL;
    /*Przenosze wskaznik na koniec listy*/
    wlst = AddItem(wlst,1);
    PrintList(wlst);
    return 0;
}

struct ListItem *AddItem(struct ListItem *list_ptr,int x)
{
    struct ListItem *pom = (struct ListItem *) malloc(sizeof(struct ListItem));
    pom->prev = list_ptr;
    list_ptr->next = pom;
    pom->next = NULL;
    pom->value = x;
    list_ptr = pom;
    return list_ptr;
}

void PrintList(struct ListItem *list_ptr)
{
    while(list_ptr->prev != 0)
    {
        printf("%d\n",list_ptr->value);
        list_ptr = list_ptr->prev;
    }
}
