#include<stdio.h>

void main()
{
	FILE *arch;
	int i = 0;
	int j;
	float resultados[10];
	char aux[4];

	arch = fopen("valores_polinomios.txt", "r");

	while(!feof(arch))
	{
		fscanf(arch, "%c%c%d%c%c %f\n", &aux[0], &aux[1], &j, &aux[2], &aux[3], &resultados[i]);
	        i++;
	}	       
	for (int j = 0; j < i; j++)
	{
		printf("%f ", resultados[j]);
	}
}


