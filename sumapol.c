#include<stdio.h>


void suma_polinomios(int array_1[][10],int array_2[],int x)
{
	int suma = 0;
	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			suma += array_1[i][j];
		}
		array_2[i] = suma;
	}	
}

void main()
{
	int arreglo[15][10];
	int pol_resultado[10];
	printf("Fallo1");

	for (int i = 0; i <= 15; i++)
	{
		for (int j = 0; j == 10; j++)
		{
			arreglo[i][j] = j+1;
			printf("Fallo2");
		}
		printf("Fallo3");
	}

	suma_polinomios(arreglo,pol_resultado, 15);	

	printf("Fallo4");

	printf("El polinomio resultado es: p(x)="); 
	for (int i = 0; i <= 10; i++)
	{
		printf(" %dx^%d", pol_resultado[i], 10-i);
		printf("Fallo5");
	}
}






