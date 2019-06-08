
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int comp(const void * p1, const void * p2);
struct wektor
{
	float x;
	float y;
	float z;
};



int main()
{
	struct wektor p[20];
	//p = (struct wektor *) malloc(sizeof(struct wektor));

	srand(time(NULL));
	FILE * plik;
	plik = fopen("WEKTORY.BIN","w+b");

	for(int i = 0; i < 20; i++)
	{
		p[i].x = rand()%10;
		p[i].y = rand()%10;
		p[i].z = rand()%10;
	}

	for(int i = 0; i < 20; i++)
	{
		printf("[%.2f,",p[i].x);
		printf("%.2f,",p[i].y);
		printf("%.2f]\n",p[i].z);

	}


    fwrite(p,sizeof(struct wektor)*20,1,plik);



	qsort(p,20,sizeof(struct wektor)*20,comp);
printf("---------------------------------------\n");
	//rewind(plik);
	fwrite(p,sizeof(struct wektor)*20,1,plik);

	rewind(plik);

	fread(p,sizeof(struct wektor)*20,1,plik);

    	for(int i = 0; i < 20; i++)
	{
		printf("[%.2f,",p[i].x);
		printf("%.2f,",p[i].y);
		printf("%.2f]\n",p[i].z);
        printf(" = %.2f\n",sqrt(pow(p[i].x,2)+pow(p[i].y,2)+pow(p[i].z,2)));
	}


	return 0;
}

int comp(const void * p1, const void * p2)
{

    const struct  wektor *w1 = (struct wektor *)p1;
    const struct  wektor *w2 = (struct wektor *)p2;
	float s1 = sqrt(pow(w1->x,2)+pow(w1->y,2)+pow(w1->z,2));
    float s2 = sqrt(pow(w2->x,2)+pow(w2->y,2)+pow(w2->z,2));
	if(s1 == s2)
		return 0;
	else if(s1 < s2)
		return -1;
    else
        return 1;
}
