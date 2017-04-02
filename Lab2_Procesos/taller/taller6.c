#include <stdio.h>
#include <unistd.h>
int main() {
	int hijo,nieto;
	hijo= (int)fork();
	if(hijo==0){
		printf("HIJO: mundo\n");
		nieto= (int)fork();
		if(nieto==0){
			printf("NIETO: !\n");
		}
	}
	else{
		printf("PADRE: Hola\n");//padre
	}
   return 0;
}