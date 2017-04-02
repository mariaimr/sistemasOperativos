#include <stdio.h> // printf, scanf
#include <stdlib.h> // malloc, fr

#define MAX_CHAR_NOMBRE 10

int main()
{	
	//Apuntador a un array de caracteres: apuntador a string
	char (*nombre)[MAX_CHAR_NOMBRE];
	//Casting a apuntador de string
	nombre= (char (*)[MAX_CHAR_NOMBRE])
		malloc(sizeof(char[MAX_CHAR_NOMBRE]));//tamaño de un string

	printf("Nombre: ");
	setbuf(stdin,NULL);
	//Scanf espera un char *: espera un string
	scanf("%s",(char *)nombre);
	//printf tambien espera un string
	printf("Hasta luego %s\n", (char *)nombre );
	//libera nombre
	//free(nombre);

	return 0;
}