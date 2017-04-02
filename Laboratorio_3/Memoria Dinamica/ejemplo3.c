#include <stdio.h> // printf, scanf
#include <stdlib.h> // malloc, free




#define MAX_NUMEROS 10 // las condiciones generalmente son constantes

//note que los parametros de las variables en main no tiene que llamarse igual
void obtenerNumeros(int *totalN, int *numEnMemoria);
int calcularDiferencia(int totalN, int *numEnMemoria);

//incluso se pueden omitir los nombres de los parametros pero indicar el tipo de parametro
//void obtenerNumeros(int *, int *)

int main()
{
	int totalNumeros, diferencia;
	//Crearemos yn apuntador a un arreglo de enteros
	int *numerosEnMemoria;
	//Casting a objetos de tipo int
	numerosEnMemoria = (int (*)) malloc(sizeof(int) * MAX_NUMEROS);

	obtenerNumeros (&totalNumeros, numerosEnMemoria); //los dos son por referencia
	diferencia= calcularDiferencia(totalNumeros,numerosEnMemoria);// primero por valor segundo por referencia

	free(numerosEnMemoria);
	printf("La diferencia de los numeros ingresados con 100 es %d \n",diferencia );

	return 0;
}

void obtenerNumeros(int *totalN, int *numEnMemoria){
	int i=0;

	//obtener vantidad de nnumeros que se van a ingresar
	printf("Cantidad de numeros a ingresar: ");
	setbuf(stdin, NULL);
	scanf("%d", totalN);

	for (i = 0; i < *ẗotalN; ++i)
	{
		printf("#%d: ", i+1);
		setbuf(stdin,NULL);

		//incremento/ decremento de apuntadores
		scanf("%d", numEnMemoria+i);
	}

}

int calcularDiferencia(int totalN, int *numEnMemoria){
	int i=0, dif=100;

	for (i = 0; i < totalN; ++i)
	{
		//recordar el incremento/decremento de apuntadores
		dif -= *(numEnMemoria+i);
	}
	return dif;
}