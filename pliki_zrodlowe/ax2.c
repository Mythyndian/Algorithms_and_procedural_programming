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
char * pom;
pom = p2;
  /* Z pominieciem znaku \0 i bez liczb*/
  // char c;
     while(*p2 != '\0')
   {
       if(*p2 >= 48 && *p2 <= 57)
        p2++;
   
      else
      {
        *p1 = *p2;
        *p1++;
        *p2++;
      }
   }
}
while(p2 != pom)
{
    *p2-- = *p1
}
/*Odwrotna kolejnosc*/
    
    
}
   /*Z pominieciem znaku \0 i bez liczb*/
  // char c;
    /*  while(*p2 != '\0')
   {
       if(*p2 >= 48 && *p2 <= 57)
        p2++;
   
      else
      {
        *p1 = *p2;
        *p1++;
        *p2++;
      }
   }
*/
