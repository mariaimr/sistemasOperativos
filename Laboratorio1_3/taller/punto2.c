/*2. Realice un programa que reciba 3 números enteros. 
Utilice un apuntador que contenga la dirección del primer número ingresado.
Utilice incrementos para “recorrer” la memoria e imprima los tres números en consola.
*/

#include <stdio.h>

int main(void)
{	
	int vec[3];
	int *p = vec;
	for (int i = 0; i < 3; ++i)
	{
		printf("ingrese el numero %d: \n", (i+1) );
		scanf("%d", &vec[i]);
	}

	for (int i = 0; i < 3; ++i)
	{
		printf("El numero %d es: %d", i+1, *(p+i));
	}

	return 0;
}