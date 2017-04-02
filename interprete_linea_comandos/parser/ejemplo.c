/*  Neyder Leoncio Daza Cardona
    Maria Isabel Martinez Rendón
    
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "parser.h"


#define TAM 150
void my_handler(int sig);
int length (const char *); 

int main ()
{
  char ** items;
  int i, num, background, j;
  char expresion[TAM];
  char str1[TAM];
  char str2[TAM];
  char comandos[8][10] = {"mipwd","mils","mikill","micd","micp","miecho","miclr","mipause"};
  int ret,comparacion,status, h;
  char (*b)[10];
  //----Captura la señal-----------------
  struct sigaction my_action;
  my_action.sa_handler = my_handler;
  my_action.sa_flags=SA_RESTART;
  sigaction(SIGINT, &my_action,NULL);
  //-------------------------------------


do{
    printf ("teclea_una_orden$ ");
    fgets (expresion, TAM, stdin);
    num = separaItems (expresion, &items, &background);
    if(num!=0){
	    strcpy(str1, "miexit");
	    ret = strcmp(str1, items[0]);//si ingresa miexit

	    if(ret==0)break;//sale del while

	    b = (char(*)[10]) comandos[0];
	    for(j=0 ;j<8; j++){
	    	strcpy(str2,  (char *) (b + j));
	    	comparacion=strcmp(str2, items[0]);
	    	if(comparacion==0){
	    		switch(j){
	    			case 0: //mipwd
	    				h= fork();//se crea un hijo
	      				if (h==0){
	        				execl("./pwd","./pwd",NULL);//se ejecuta el ejecutable pwd
	        				exit(0);
	     				}else{
	       					wait(&status);// el padre espera a que el hijo finalice
	     				}
	     				j=7;
	    			break;
	    			case 1:
	    				h= fork();//se crea un hijo
	      				if (h==0){
	        				execl("./ls","./ls ",items[1],NULL);//se ejecuta el ejecutable ls
	        				exit(0);
	     				}else{
	       					wait(&status);// el padre espera a que el hijo finalice
	     				}
	     				j=7;
	    			break;
	    			case 2:
	    				h= fork();//se crea un hijo
	      				if (h==0){
	        				execl("./kill","./kill ",items[1],items[2],NULL);//se ejecuta el ejecutable ls
	        				exit(0);
	     				}else{
	       					wait(&status);// el padre espera a que el hijo finalice
	     				}
	     				j=7;
	    			break;
	    			case 3:
	    				h= fork();//se crea un hijo
	      				if (h==0){
	        				execl("./cd","./cd ",items[1],NULL);//PREGUNTAR
	        				exit(0);
	     				}else{
	       					wait(&status);// el padre espera a que el hijo finalice
	     				}
	     				j=7;
	    			break;
	    			case 4:
	    				h= fork();//se crea un hijo
	      				if (h==0){
	        				execl("./cp","./cp",items[1],items[2],NULL);//se ejecuta el ejecutable ls
	        				exit(0);
	     				}else{
	       					wait(&status);// el padre espera a que el hijo finalice
	     				}
	     				j=7;
	    			break;
	    			case 5:
	    				h= fork();//se crea un hijo
	      				if (h==0){
	        				execl("./echo","./echo",items[1],items[2],NULL);//se ejecuta el ejecutable ls
	        				exit(0);
	     				}else{
	       					wait(&status);// el padre espera a que el hijo finalice
	     				}
	     				j=7;
	    			break;
	    			case 6:
	    				h= fork();//se crea un hijo
	      				if (h==0){
	        				execl("./clr","./clr",NULL);//se ejecuta el ejecutable ls
	        				exit(0);
	     				}else{
	       					wait(&status);// el padre espera a que el hijo finalice
	     				}
	     				j=7;

	    			break;
	    			case 7:
	    				h= fork();//se crea un hijo
	      				if (h==0){
	        				execl("./pause","./pause",NULL);//se ejecuta el ejecutable ls
	        				exit(0);
	     				}else{
	       					wait(&status);// el padre espera a que el hijo finalice
	     				}
	     				j=7;
	    			break;
	    		}
	    	}else{
	    		if (j==7){
	    			printf("Comando no encontrado\n");
	    		}
	    	}
	    }
    }
  }while(ret !=0);// mientras la instruccion sea diferente de miexit 
  return 0;
}

void my_handler(int sig){
	char * mensaje ="He capturado una señal de TERMINACIÓN\nteclea_una_orden$ ";
	write(1,mensaje,length(mensaje));

}
int length (const char * d){
	int i;
	for (i = 0;d[i]!='\0'; i++);
	return i;
}
