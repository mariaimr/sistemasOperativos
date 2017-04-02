#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

void* calcular_primo(void* arg);

int main(){
	pthread_t hilo_id;
	int cual_primo=5000;
	int primo;

	//inicia el hilo, se requiere el 5000ésimo número primo
	pthread_create(&hilo_id,NULL,&calcular_primo,&cual_primo);
	//puedo hacer algo mentras ...... si quiero
	//espero que el número sea calculado y me sea entregado
	pthread_join(hilo_id,(void*)&primo);	
	//imprimo el numero entregado
	printf("El número primo es %d.\n",primo);
	return 0;
}

/*Calcula los números primos sucesivamente
retorma el N-ésimo número primo
donde N es el valor apuntado por *ARG
*/
void* calcular_primo(void* arg){
	int candidato=2;
	int n = *((int*)arg);
	while(1){
		int factor;
		int es_primo=1;
		for(factor=2;factor<candidato;++factor)
		if(candidato % factor==0){
			es_primo=0;
			break;
		}
		if(es_primo){
			if(--n==0) return (void*)(intptr_t)candidato;
		}
		++candidato;
	}
	return NULL;
}