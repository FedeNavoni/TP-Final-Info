#include<stdio.h>

void CARGA(float array[][11], int *lines)   //Declaracion de la subrutina "carga"
{
        FILE *arch;      //Declaracion de variable de tipo archivo de nombre arch (si o si va con *)
        int i = 0;       //Declaracion de variable entera llamada "i", para usar de contador

        arch = fopen("polinomios.txt", "r");     /*Asigno a la variable arch la funcion ABRIR con parametro 1: la ruta del archivo (como esta en la misma carpeta no hace falta el resto de la ruta) parametro 2: modo de apertura de archivo (r = lectura, w = escritura) */

        if (arch == NULL){     // Verificacion de que se abre el archivo (no hace falta, no lo enseñaron en clase)
                printf("fallo la lectura");
        }
        while (!feof(arch)){      //Repetir mientras el final de archivo sea falso (osea mientras no termine el archivo)
                fscanf(arch, "%f %f %f %f %f %f %f %f %f %f %f\n", &array[i][0], &array[i][1], &array[i][2], &array[i][3], &array[i][4], &array[i][5], &array[i][6], &array[i][7], &array[i][8], &array[i][9], &array[i][10]);    /*Funcion LEER archivo, en este caso lee un renglon entero por repeticion, lee 11 numeros reales y los guarda en el arreglo*/
                i++;    //Incremento el contador i que marca el numero de fila del arreglo, osea cantidad de polinomios
        }
	fclose(arch);   //Cierro el archivo
	*lines = i;    //Le asigno a la variable lines el valor de i para devolver al algoritmo principal la cantidad de polinomios
}

void SUMA_POLI(float array_1[][11],float array_2[],int x)  /*Declaracion de la subrutina SUMA_POLI con argumentos: 1 arreglo bidimensional, 1 arreglo unidimensional y 1 variable simple */ 
{
        float suma = 0;     //Declaro la variable real "suma" y la inicializo en 0
        for (int i = 0; i <= 10; i++)    //Repetir para de 0 a 10 (porque los arreglos empiezan a contar del 0)
        {
                for (int j = 0; j <= x; j++)   //Repetir para de 0 a x(variable ingresada como argumento donde se encuentra la cantidad de polinomios
                {
                        suma += array_1[j][i];   /*En cada instancia de los repetir (1er repetir recorre columnas, 2ndo recorre las filas) se le asigna a suma el valor de la suma de los coeficientes de polinomios de igual grado, es decir de la misma columna*/
                }
                array_2[i] = suma;   //Le asigno a cada elemento del arreglo donde esta el resultado el valor de la suma de la columna
                suma = 0;     //Reinicio suma en 0 para sumar la proxima columna
        }
}

float potencia(float base, int exponente)
{
	float resultado = base;
	for(int i = 1; i < exponente; i++){
		resultado = resultado * base;
	}
	if(exponente == 0){
		resultado = 1;
	}
	return (resultado);
}

float EVALUA_enX(int pol, float x, float array[][11])
{
	float eval = 0;
	float pot;

	for (int i = 0; i <= 10 ; i++)
	{
		pot = potencia(x, 10-i);
		eval = eval + array[pol][i] * pot;
	}
	return (eval);
}

void Ordenar(int *x1, int *x2)
{
	int aux1 = *x1;
	int aux2 = *x2;
	int aux3;

	if (aux1 > aux2)
	{
		aux3 = aux1;
		aux1 = aux2;
		aux2 = aux3;
	}

	*x1 = aux1;
	*x2 = aux2;
}

void EVALUA_INTERVALO(int x1, int x2, float array[][11], int pol)
{
	FILE *arch;
	int i;

	arch = fopen("valores_polinomios.txt", "w");

	for ( i = x1; i <= x2; i++)
	{
		fprintf(arch, "P(%d)= %2.1f\n", i, EVALUA_enX(pol, i, array));
	}
	fclose(arch);
}

void GRAFICAR_HISTOGRAMA(int x1, int x2) //Declaro la subrutina GRAFICAR_HISTOGRAMA a la cual se le ingresa por parametros 2 enteros (los extremos del intervalo a evaluar
{
	FILE *arch;   //Declaro una variable de tipo archivo para luego abrir el archivo
	char aux[4];   //Declaro un arreglo de 4 caracteres
	int i = 0;   //Declaro un entero para usar como indice
	int j;   //Declaro un entero para usar como indice	
	int cantval = x2 - x1 + 1;   //Declaro un entero para la cantidad de valores que saco del archivo que es igual a el extremo final del intervalo menos la cantidad inicial del intervalo +1 
	int marcador = 0;   //Declaro una bandera que se active cuando un intervalo tiene mas de 30 valores
	float valores[cantval];   //Declaro un arreglo real con la misma cantidad de elementos que leo del archivo
	float intervalos[6] = {0,0,0,0,0,0};   //Declaro un arreglo real donde cada elemento representa un intervalo y cuenta la cantidad de valores que caen dentro de el mismo

	arch = fopen("valores_polinomios.txt", "r"); //Asigno a la variable arch la funcion de abrir el archivo en modo lectura

	while(!feof(arch))  //Repetir mientras no haya un fin de arcivo
	{
		fscanf(arch, "%c%c%d%c%c %f\n", &aux[0], &aux[1], &j, &aux[2], &aux[3], &valores[i]);  //Leo un renglon completo y guardo el valor en el arreglo valores
		i++;  //Este indice es para que en cada renglon cambie la posicion a guardar en el arreglo valores
	}
	for(i = 0; i < cantval; i++)   //Repetir para de 0(porque los arreglos cuentan desde 0) a la cantidad de valores del archivo para recorrer el arreglo valores y asi ubicar cada valor en su intervalo correspondiente
	{
		if(valores[i] <= -20){    //Si el valor es menor a -20 va en el primer elemento del arreglo intervalos
			intervalos[0] ++;
		}
		if(valores[i] > -20 && valores[i] <= -10){  //Si el valor esta entre -20 y -10 va en el segundo elemento del arreglo intervalos
			intervalos[1] ++;
		}
		if(valores[i] > -10 && valores[i] <= 0){  //Si el valor esta entre -10 y 0 va en el tercer elemento del arreglo intervalos
			intervalos[2] ++;
		}
		if(valores[i] > 0 && valores[i] <= 10){   //Si el valor esta entre 0 y 10 va en el cuarto elemento del arreglo intervalos
			intervalos[3] ++;
		}
		if(valores[i] > 10 && valores[i] <= 20){  //Si el valor esta entre 10 y 20 va en el quinto elemento del arreglo intervalos
			intervalos[4] ++;
		}
		if(valores[i] > 20){   //Si el valor es mayor a 20 va en el sexto elemento del arreglo intervalos
			intervalos[5] ++;
		}
	}
	for(i = 0; i <= 5; i++){   //Repetir para de 0 a 5 para recorrer el arreglo intervalos
		if(intervalos[i] > 30){   //Si alguno de los elementos del arreglo es mayor a 30 entonces activa la bandera "marcador"
			marcador = 1;
		}
	}
	if(marcador == 1)   //Si la bandera esta activada entonces imprime el intervalo con el numero de valores que hay dentro de el
	{
		printf("Valor de frecuencias de cada rango:\n");	
		printf("(-Inf, -20] = %2.1f\n", intervalos[0]);   //EL %2.1f es para que muestre unicamente un digito despues del punto
		printf("(-20, -10] = %2.1f\n", intervalos[1]);   //Si no imprime un real como 0.00000000 y queda feo
		printf("(-10, 0] = %2.1f\n", intervalos[2]);
		printf("(0, 10] = %2.1f\n", intervalos[3]);
		printf("(10, 20] = %2.1f\n", intervalos[4]);
		printf("(20, Inf) = %2.1f\n", intervalos[5]);
	}
	else   //Si la bandera no se activa entonces muestra cada intervalo con un igual por cada valor que hay dentro del mismo
	{
		printf("Grafica del histograma:\n");	
		printf("\n(-Inf, -20]	");
		for(int a = 0; a < intervalos[0]; a++){  //como en el arreglo intervalos tenemos guardado la cantidad de valores que hay dentro del intervalo el repetir para de 0 a este valor imprimira un = por cada valor
			printf("=");
		}
		printf("\n(-20, -10] 	");
		for(int a = 0; a < intervalos[1]; a++){
			printf("=");
		}
		printf("\n(-10, 0]   	");
		for(int a = 0; a < intervalos[2]; a++){
			printf("=");
		}
		printf("\n(0, 10]    	");
		for(int a = 0; a < intervalos[3]; a++){
			printf("=");
		}
		printf("\n(10, 20]   	");
		for(int a = 0; a < intervalos[4]; a++){
			printf("=");
		}
		printf("\n(20, Inf)  	");
		for(int a = 0; a < intervalos[5]; a++){
			printf("=");
		}
	}
}


void main()
{
	float polinomios[15][11];   //Declaro el arreglo real bidimensional donde voy a guardar los polinomios
	float resul_suma[11];    //Declaro el arreglo real unidimensional donde voy a guardar el polinomio resultado de la suma
	int cantpol;    //Declaro la variable entera donde voy a guardar la cantidad de polinomios dentro del archivo
	int opc;   //Declaro la variable entera donde leo la opcion elegida en el menu
	int salida = 0;   //Declaro variable para salida del programa
	int nro;       // Declaro variable para opcion de polinomio en evaluacion
	float resul_eval; // Declaro variable real para mostrar el resultad de evaluar el polinomio en x
	float val_x; // Declaro variable real para evaluar el polinomio
	int extremo1, extremo2;   //Declaro variables enteras para los extremos del intervalo del item 3
	int marcador = 0; //Declaro variable entera para verificar el paso por la opcion 3

	CARGA(polinomios, &cantpol);    /*Llamo a la variable CARGA para que lea el archivo y guarde los polinomios en el arreglo "polinomios" y la cantidad de polinomios en la variable "cantpol"*/

	
	while (salida == 0){
        	printf("\tMenú\n1- Sumar polinomios\n2- Evaluar un polinomio determinado en x\n3- Evaluar un polinomio determinado en el intervalo [x1, x2]\n4- Graficar un polinomio determinado en el intervalo [x1, x2]\n5- Salir del programa\n");   //Muestro el menu de opciones

        	scanf("%d", &opc);    //Leo la opcion elegida y la guardo en opc
        	while (opc < 1 || opc > 5){     //Valido que la opcion elegida este entre 1 y 5
                	printf("Opcion no valida! Vuelva a elegir.\n");
                	scanf("%d", &opc);
        	}
        	switch (opc)
        	{
                	case 1:
				SUMA_POLI(polinomios, resul_suma, cantpol);

				printf ("\nEl resultado de la suma de todos los polinomios es:\n");
				printf ("P(x) =");
				for (int j= 0; j <= 10; j++){
              				if (resul_suma[j] != 0){
                      				printf("%2.1fx^%d  ", resul_suma[j], 10-j);
              				}
      				}
      				printf("\n");

                        	break;

                	case 2:
				printf("\nEliga un polinomio:\n\n");
				for(int i = 0; i < cantpol; i++)
				{  
					printf("%d_ ", i+1);
					for( int j = 0; j <= 10; j++)
					{
						if (polinomios[i][j] != 0){
							printf("%2.1fx^%d ", polinomios[i][j], 10-j);
						}
					}
					printf("\n");
				}
				scanf ("%d", &nro);
				while(nro < 1 || nro > cantpol)
				{
					printf("Opcion no valida! Vuelva a ingresar.\n");
					scanf("%d", &nro);
				}	
				printf("\nIngrese un valor de X: ");
				scanf("%f", &val_x);
				nro = nro - 1;
				resul_eval = EVALUA_enX(nro, val_x, polinomios);
                        	printf("\nEl resultado de evaluar el polinomio %d en %2.1f es: \nP(%2.1f)=%2.1f\n", nro + 1, val_x, val_x, resul_eval);
				break;
				
                	case 3:

				printf("\nEliga un polinomio:\n\n");
				for(int i = 0; i < cantpol; i++)
				{  
					printf("%d_ ", i+1);
					for( int j = 0; j <= 10; j++)
					{
						if (polinomios[i][j] != 0){
							printf("%2.1fx^%d ", polinomios[i][j], 10-j);
						}
					}
					printf("\n");
				}
				scanf ("%d", &nro);
				while(nro < 1 || nro > cantpol)
				{
					printf("Opcion no valida! Vuelva a ingresar.\n");
					scanf("%d", &nro);
				}	
				printf("\nIngrese los extremos del intervalo a evaluar:\n");
				scanf("%d", &extremo1);
				scanf("%d", &extremo2);
				Ordenar(&extremo1, &extremo2);
				nro = nro - 1;
				EVALUA_INTERVALO(extremo1, extremo2, polinomios, nro);
				marcador = 1;
				printf("Se guardaron los resultados en el archivo");
                        	break;

                case 4:
				if (marcador == 0){
					printf("Se requiere que realice previamente la opcion 3");
					break;
				}
				GRAFICAR_HISTOGRAMA(extremo1, extremo2);
                        	break;

                	case 5:
				salida = 1;
                        	break;

        	}
		printf(" \n \n \n");
	}
}











