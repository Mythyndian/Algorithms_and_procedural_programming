
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

    fwrite(p,sizeof(struct wektor),1,plik);

	rewind(plik);

	qsort(p,20,sizeof(struct wektor),comp);

	fwrite(p,sizeof(struct wektor),1,plik);

	fread(p,sizeof(struct wektor),1,plik);

    	for(int i = 0; i < 20; i++)
	{
		printf("[%.2f,",p[i].x);
		printf("%.2f,",p[i].y);
		printf("%.2f]\n",p[i].z);
	}


	return 0;
}

int comp(const void * p1, const void * p2)
{
    struct wektor *w1 = (struct wektor*)p1;
	struct wektor *w2 = (struct wektor*)p2;
	if(sqrt((p1->x,2)+(p1->y,2)+(p1->z,2)) == sqrt((p2->x,2)+(p2->y,2)+(p2->z,2)))
		return 0;
	else if((sqrt((p1->x,2)+(p1->y,2)+(p1->z,2))) < (sqrt((p2->x,2)+(p2->y,2)+(p2->z,2))))
		return -1;
else
    return 1;
}
