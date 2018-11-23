#include<stdio.h>

void main()
{
	float num[11];
	FILE *arch;
	float lec;
	int i = 0;

	arch = fopen("polinomios.txt", "r");

	if (arch == NULL){
		printf("fallo la lectura");
	}
	else {
		while (feof(arch) == 0){
			for (i; i <= 11; i++){
			fscanf(arch, "%f", &lec);
			num[i] = lec;
			}
			}
	printf("%f\n", num[7]);
	}	
}
	
