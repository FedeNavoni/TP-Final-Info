#include<stdio.h>

void CARGA(float array[][11])
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
}

void SUMA_POLI(float array_1[][11],float array_2[],int x)
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
	float polinomios[15][11];
	float resultado[11];
	int *cantpol;

	CARGA(polinomios);

	for (int a = 0; a < 9; a++){
                for (int j= 0; j <= 10; j++){
                        if (polinomios[a][j] != 0){
                                printf("%2.1fx^%d  ", polinomios[a][j], 10-j);
			}
		}
		printf("\n");
	}

	SUMA_POLI(polinomios, resultado, 9);

        for (int j= 0; j <= 10; j++){
       		if (resultado[j] != 0){
        		printf("%2.1fx^%d  ", resultado[j], 10-j);
		}
	}
	printf("\n");
}
