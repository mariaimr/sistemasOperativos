#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int n= sizeof("Presione [Enter] para continuar: ... ");
	write(1,"Presione [Enter] para continuar: ... ",n);
	
	while ( getchar() != '\n');
	return 0;
}