#include <stdio.h>
/* Declaracion de funciones (prototipos).*/
void swap(int *d1, int *d2);

int main(void)
{
	int x= 1;
	int y= 2;

	int *p = &y; //agregado

	printf("Valor de y pasado por el apuntador: %d\n",*p );

	printf("Valor de x: %d\n",x );
	printf("Valor de y: %d\n",*p );

	swap(&x, p); //paso por referencia
	printf("Valor de x: %d\n",x );
	printf("Valor de y: %d\n",*p );

	return 0;
}

//Implementacion de funciones
void swap(int *d1, int *d2){
	int temp;
	temp = *d1;
	*d1=*d2;
	*d2=temp;
}