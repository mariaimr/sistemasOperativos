#include <stdio.h>
/* Declaracion de funciones (prototipos).*/
void swap(int *d1, int *d2);

int main(void)
{
	int x= 1;
	int y= 2;

	printf("Valor de x: %d\n",x );
	printf("Valor de y: %d\n",y );

	//swap(x, y); //Paso por valor
	swap(&x, &y); //paso por referencia
	printf("Valor de x: %d\n",x );
	printf("Valor de y: %d\n",y );

	return 0;
}

//Implementacion de funciones
void swap(int *d1, int *d2){
	int temp;
	temp = *d1;
	*d1=*d2;
	*d2=temp;
}