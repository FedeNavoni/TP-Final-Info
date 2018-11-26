#include<stdio.h>

void main()
{
	int opc;
	printf("\tMenú\n1- Sumar polinomios\n2- Evaluar un polinomio determinado en x\n3- Evaluar un polinomio determinado en el intervalo [x1, x2]\n4- Graficar un polinomio determinado en el intervalo [x1, x2]\n5- Salir del programa\n");
	scanf("%d", &opc);
	while (opc < 1 || opc > 5){
		printf("Opcion no valida! Vuelva a elegir.\n");
		scanf("%d", &opc);
	}
	switch (opc)
	{
		case 1:
			printf("Elegiste la opcion 1\n");
			break;

		case 2:
			printf("Elegiste la opcion 2\n");
			break;

		case 3:
			printf("Elegiste la opcion 3\n");
			break;
	
		case 4:
			printf("Elegiste la opcion 4\n");
			break;

		case 5:
			printf("Elegiste la opcion 5\n");
			break;
	
	}
}
