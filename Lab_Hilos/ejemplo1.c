#include <pthread.h>
#include <stdio.h>

void* imprime_x (void* unused){
	while(1) fputc ('x', stderr);
	return NULL;
}
int main()
{
	pthread_t id_hilo; // variable para almacenar la identificación del hilo  a crear.
	//crea un nuevo hilo sobre la funcion imprime_x
	pthread_create (&id_hilo,NULL,&imprime_x,NULL); // crea el hilo que comienza su ejecucion con la función imprime_x
	/*
		Argumentos de pthread: 
			1. apuntador a la variable de tipo pthread donde dejara el PID del hilo creado--> &id_hilo
			2. apuntador a una estructura de atributos del hilo recien creado --> NULL
			3. apuntador a la función a ejecutar por el hilo (la funcion debe ser tipo void* y argumento void*) --> &imprime_x
			4. argumentos tipo void* a pasarle al hilo recien creado --> NULL

	*/
	//imprime 'o' en la salida de error stderr
	
	while(1) fputc ('o',stderr);
	return 0;
}