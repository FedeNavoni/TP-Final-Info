#include<stdio.h>

void main()
{
	int num[11];
	FILE *arch;
	int lec;
	int i = 0;

	arch = fopen("polinomios.txt", "r");

	if (arch == NULL){
		printf("fallo la lectura");
	}
	else {
		while (feof == 0){
			fscanf(arch, "%d", &lec);
			num[i] = lec;
			i++;
			
			}
	printf("%d\n", num[4]);
	}	
}
	
