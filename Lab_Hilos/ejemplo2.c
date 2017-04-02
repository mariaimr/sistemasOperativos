#include <pthread.h>
#include <stdio.h>

//Esta estructura sirve para pasar parametros a el hilo
struct parametros_hilo{
	//parametro 1: caracter a imprimir
	char caracter;
	//parametro 2:  número de veces que se desea imprimir
	int contador;
};

/*esta funcion imprime un número de caracteres a la salida de error
tal y como lo indica el parametro de la funion
*/
void* imprimir_caracter (void* parametros){
	//se hace un cast a tipo de dato correcto
	struct parametros_hilo* p=(struct parametros_hilo*)parametros;
	int i;
	for(i=0; i< p->contador; i++)
		fputc(p->caracter, stderr);
	return NULL;
}

//programa principal
int main(){
	pthread_t id_hilo_1;
	pthread_t id_hilo_2;

	struct parametros_hilo hilo1_param;
	struct parametros_hilo hilo2_param;

	//crea un hilo para imprimir 30,000 x
	hilo1_param.caracter='x';
	hilo1_param.contador=30000; 
	pthread_create (&id_hilo_1,NULL,&imprimir_caracter,&hilo1_param); //puntero tipo void* --> puntero generico

	//crea un hilo para imprimir 20,000 o
	hilo2_param.caracter='o';
	hilo2_param.contador=20000;
	pthread_create (&id_hilo_2,NULL,&imprimir_caracter,&hilo2_param);
	//insertar aquí
	pthread_join (id_hilo_1,NULL); //espera por que termine el hilo 1 (cuando la funcion retorna void*)
	pthread_join (id_hilo_2,NULL);//espera por que termine el hilo 2
	/*
	la funcion retorna *void, el cual es interpretado
     como el estado de terminado por pthread_join*/
	return 0;
}