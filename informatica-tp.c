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
	int extremo1, extremo2;

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
					scanf("%d\n", &nro);
				}	
				printf("Ingrese un valor de X: ");
				scanf("%f", &val_x);
				nro = nro - 1;
				resul_eval = EVALUA_enX(nro, val_x, polinomios);
                        	printf("\nEl resultado de evaluar el polinomio %d en %2.1f es: \nP(%2.1f)=%2.1f\n", nro, val_x, val_x, resul_eval);
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
					scanf("%d\n", &nro);
				}	
				printf("Ingrese los extremos del intervalo a evaluar:\n");
				scanf("%d", &extremo1);
				scanf("%d", &extremo2);
				Ordenar(&extremo1, &extremo2);
				EVALUA_INTERVALO(extremo1, extremo2);
				printf("Se guardaron los resultados en el archivo");
                        	break;

                	case 4:
                        	printf("Elegiste la opcion 4\n");
                        	break;

                	case 5:
				salida = 1;
                        	break;

        	}
		printf(" \n \n \n");
	}
}











