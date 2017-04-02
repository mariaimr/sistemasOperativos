#include <stdio.h>
#include <stdlib.h>

const char FILE_NAME[]= "input.txt";
int main()
{
	int count =0; //numero de caracteres leidos
	FILE *in_file;
	int ch;
	//abrir el archivo
	in_file = fopen(FILE_NAME, "r"); // fopen= retorna un apuntador hacia el  archivo abierto en modo lectura
	// SIEMPRE realice esta verificacion
	if(in_file==NULL){ //no existe el archivo
		printf("NO PUEDE ABRIRSE %s\n",FILE_NAME );
		exit(8);
	}
	//leer archivo
	while(1){
		ch = fgetc(in_file);// retorna el caracter leido como caracter sin signo pero lo emite como entero
		printf("%c\n", ch );
		if (ch==EOF) //lea hasta el final del archivo
		{
			break;
		}
		++count;
	}
	fputc('m', in_file);
	printf("Numero de caracteres en el archivo %s: %d \n",FILE_NAME,count );
	fclose(in_file);

	return 0;	
}