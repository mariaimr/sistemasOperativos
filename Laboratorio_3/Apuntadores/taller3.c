#include <stdio.h>

int main()
{
	int num1 = 	10;
	int num2 = 5;
	int resultado = 0;

	int *ptrSumando1;
	int *ptrSumando2;

	ptrSumando1 = &num1;
	ptrSumando2 = &num2;

	resultado = *ptrSumando1 + *ptrSumando2; // se trabaja con los apuntadores y no las variables

	*ptrSumando1= 6;  //asigna un nuevo valor a la variable
	*ptrSumando2= 11;

	printf("%d numero 1: \n", *ptrSumando1 );
	printf("%d numero 2: \n", *ptrSumando2 );
	printf("%d resultado: \n", resultado );

	ptrSumando1 = ptrSumando1 + 1; // se avanza en la posición de memoria
	*ptrSumando1 = 200;
	printf("%d numero 2: \n", num2);
	printf(" ptrSumando1: %d , ptrSumando2: %d \n", *ptrSumando1, *ptrSumando2 );

//istrucciones necesarias para modificar resultado con ptrSumando1
	ptrSumando1 = &resultado;
	*ptrSumando1 = *ptrSumando1 +1; 
	printf("%d \n", *ptrSumando1 );
//istrucciones necesarias para modificar resultado con ptrSumando2
	ptrSumando2 = &resultado;
	*ptrSumando2 = *ptrSumando2 +1;

	
	return 0;
}