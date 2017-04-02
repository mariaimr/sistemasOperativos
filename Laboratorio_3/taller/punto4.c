/*4. Realice un programa que calcule el promedio 
de los valores de un arreglo de 100 posiciones. 
El programa debe generar el arreglo 
automáticamente y luego llamar una función que 
calcule el promedio.

1- Reciba parametro para el tamaño del vector
2- Crear una función que asigne memoria e inicialice  el arreglo
3- Crear una funcion que calcule el promedio

atoi(numPtr)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double promedio (int *vec,int n);
int* arreglo (int n);

int main(int argc, char const *argv[])
{
	int tam = atoi(argv[1]);
	printf("Tamaño del vector: %d \n", tam);
	int *vec;
	vec =arreglo(tam);
	//printf("memoria %p \n", vec );
	int i;
	for (i = 0; i < tam; ++i)
	{
		printf("Valor del vector en la posicion [%d]= %d \n",i+1, *(vec+i) );
	}
	return 0;

}

double promedio (int *vec, int n){
	double prom =0;
	int suma=0;
	int i;
	for (i = 0; i < n; ++i)
	{
		suma = suma + *(vec+i);
	}
	printf("El valor de la suma es: %d\n",suma );
	prom = suma/n;
	return prom;
}

int* arreglo (int n){
	int *vector = (int*)malloc(sizeof(int)*n);

	int randon;
	double prom;
	srand(time(NULL));
	int i; 

	for (i =0; i < n; ++i)
	{
		randon = rand() % 200;
		*(vector +i)= randon;
	}

	prom = promedio(vector, n);
	printf("%.4f \n", prom);
	return vector;
}