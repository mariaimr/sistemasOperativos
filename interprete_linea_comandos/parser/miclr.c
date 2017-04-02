#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{	
	
	int n= sizeof("\033[2J\033[1;1H");
	write(1,"\033[2J\033[1;1H",n);
	return 0;
}