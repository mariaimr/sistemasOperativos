#include <stdio.h>
int  main(void)
{
	int vec[4]={1,2,3,4};
	int a= *(vec +1);// vec en la posicion 1+1
	int b= *vec + 1;// devuelve lo que tenga vec en la posicion 1 y le suma 1

	printf("a=%d, b=%d\n",a,b );
	return 0;
}