#include <stdio.h> // printf, scanf
#include <stdlib.h> // malloc, free

int main(void)
{	//Malloc retorna un apuntador
	int *edad;

	//el apuntador que retorna Malloc es generico:
	edad= (int *) malloc(sizeof(int));	

	printf("Edad en años: " );
	setbuf(stdin,NULL);
	scanf("%d", edad);

	printf("Usted tiene %d meses de vida\n", (*edad)*12);
	//se libera la vble
	free(edad);
	return 0;
}