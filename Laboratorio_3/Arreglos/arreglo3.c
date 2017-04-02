#include <stdio.h>
 char nombres[3][10]={"MARIA","DANIELA","CARLA"};	
 int main(void)
 {
 	char i;
 	char *a;
 	char (*b)[10];

 	a = (char *) nombres; //obtiene el nombre de la primera posicion del vector
 	printf("El nombre es: %s \n",a );

 	b = (char (*)[10]) nombres[0]; 
 	printf("b: %p \n", b );

 	for (i = 0; i < 3; ++i)
 	{
 		printf("El nombre [%d] es %s \n",i,(char *)(b+i));
 	}
 	return 0;
 }