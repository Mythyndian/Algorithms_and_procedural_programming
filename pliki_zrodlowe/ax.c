/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void cop(char *p1, char const *p2);
int main()
{
    char napis[50];
    char *s;
    char *n = fgets(napis,50,stdin);
    s = (char *) malloc(sizeof(napis));
    
    cop(s,napis);
    puts(s);
    return 0;
}

void cop(char *p1, char const *p2)
{
    /*Z pominieciem znaku \0 i bez liczb*/
    while(*p1 = *p2)
    {
        if(*p1 >= 48 && *p1 <= 57)
        {
            p2++;
            
        }
    
        else
        {
            p1++;
            p2++;
        }
    }
    /*Odwrotna kolejnosc*/
    
    
}
