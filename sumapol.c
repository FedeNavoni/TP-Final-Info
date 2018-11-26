#include<stdio.h>


void suma_polinomios(float array_1[][11],float array_2[],int x)
{
	float suma = 0;
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			suma += array_1[j][i];
		}
		array_2[i] = suma;
		suma = 0;
	}	
}

void main()
{
	float arreglo[2][11] = {{1,2,3,4,5,6,7,8,9,10,11},{1,2,3,4,5,6,7,8,9,10,11}};
	float pol_resultado[11];

	suma_polinomios(arreglo,pol_resultado, 2);	

	printf("El polinomio resultado es: p(x)="); 
	for (int i = 0; i <= 10; i++)
	{
		printf(" %fx^%d", pol_resultado[i], 10-i);
	}
	printf("\n");
	printf("El polinomio 1 es: p(x)="); 
	for (int i = 0; i <= 10; i++)
	{
		printf(" %fx^%d", arreglo[0][i], 10-i);
	}
	printf("\n");
	printf("El polinomio 2 es: p(x)="); 
	for (int i = 0; i <= 10; i++)
	{
		printf(" %fx^%d", arreglo[1][i], 10-i);
	}
	printf("\n");
	printf(" Arreglo[0][1]: %f\n", arreglo[0][3]); 
}






