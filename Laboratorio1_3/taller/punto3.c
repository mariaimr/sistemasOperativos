/*3. Realice un programa que determine cuál es el valor más 
grande en un arreglo de 100 posiciones. 
El programa debe generar el arreglo automáticamente.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int mayor (int vec[],int n);
int main(void)
{
	int vec [100];
	int randon, mayor1;
	srand(time(NULL)); 
	for (int i = 0; i < 100; ++i)
	{
		randon = rand() % 2000;
		vec[i] = randon;
	}

	mayor1 = mayor(vec, 100);
	printf("%d \n", mayor1);
	return 0;

}

int mayor (int vec[], int n){
	int mayor =0, cont;
	for (int i = 0; i < n; ++i)
	{
		cont = vec[i];
		if(cont > mayor){
			mayor = cont;
		}
	}
	return mayor;
}