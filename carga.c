#include<stdio.h>

void main()
{
	float num[15][11];
	FILE *arch;
	float lec;
	int i = 0;
	int j = 0;

	arch = fopen("polinomios.txt", "r");

	if (arch == NULL){
		printf("fallo la lectura");
	}
	else {
		while (feof(arch) == 0){
			for (i; i <= 11; i++){
				fscanf(arch, "%f", &lec);
				num[j][i] = lec;
				}
			j++;
			printf("%d\n", feof(arch));
			}
	printf("%f\n %d\n %d\n", num[0][4], i, j);
	}	
}
	
