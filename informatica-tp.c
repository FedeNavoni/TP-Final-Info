#include<stdio.h>

void CARGA(float array[][11],int *x)
{
        FILE *arch;
        int i = 0;

        arch = fopen("polinomios.txt", "r");

        if (arch == NULL){
                printf("fallo la lectura");
        }
        while (!feof(arch)){
                fscanf(arch, "%f %f %f %f %f %f %f %f %f %f %f\n", &array[i][0], &array[i][1], &array[i][2], &array[i][3], &array[i][4], &array[i][5], &array[i][6], &array[i][7], &array[i][8], &array[i][9], &array[i][10]);
                i++;
        }
	fclose(arch);
	printf("%d\n", i);
	*x = i;
}


void main()
{
	float polinomios[15][11];
	int *cantpol;

	CARGA(polinomios, cantpol);

	printf("%f %f ", polinomios[0][5], polinomios[2][5]);
}
