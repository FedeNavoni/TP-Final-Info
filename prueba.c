#include<stdio.h>

void main()
{

	int array[15][10];
	printf("Probando\n");
	int i;
	int j;
	for (i = 0; i < 15; i++)
	{
		for (j=0; j < 10; j++)
		{
			array [i][j] = i+1;
		}
	}
	for (i = 0; i < 15; i++)
	{
		for (j=0; j < 10; j++)
		{
		printf(" %d", array[i][j]);
		}
		printf(" \n");
	}

}
