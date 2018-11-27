#include<stdio.h>

void main()
{
	float num[15][10];
	FILE *arch;
	int j = 0;
	int i = 0;

	arch = fopen("polinomios.txt", "r");

	if (arch == NULL){
		printf("fallo la lectura");
	}
	while (!feof(arch)){
		fscanf(arch, "%f %f %f %f %f %f %f %f %f %f %f\n", &num[i][0], &num[i][1], &num[i][2], &num[i][3], &num[i][4], &num[i][5], &num[i][6], &num[i][7], &num[i][8], &num[i][9], &num[i][10]);
		i++;
	}	
	printf("%2.1f\n%2.1f\n%d\n", num[2][0], num[4][6], i);
	for (int a = 0; a < i; a++){
		for (j= 0; j <= 10; j++){
			printf("%2.1fx^%d  ", num[a][j], 10-j);
		}
		printf(" \n");
	}
}


	
