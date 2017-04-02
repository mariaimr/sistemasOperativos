/* 
Realizar una calculadora de dos variables usando un menú de selección,
como se muestra a continuación:
MENU
1. Suma
2. Resta
3. Multiplicación
4. División
Seleccione una opción:
Notas:
● El usuario deberá ingresar el carácter “ ” para finalizar el programa.
● Los números ingresados y calculados deben tener 4 cifras decimales como
máximo.
● Guarde un registro en memoria dinámica de las últimas cinco operaciones
realizadas con la calculadora (un log de operaciones). Al finalizar la aplicación
imprime en consola esta lista de operaciones como se muestra a continuación:
Operaciones realizadas:
5 * 3 = 15
6 - 4 = 2
9 / 3 = 3
3 * 10 = 30
Saliendo de la aplicación...
*/
#include <stdio.h>

int main(void){
	
	float x,y; 
	int opcion;
	float log [5][30];
	
			
	do
	{
		printf("ingrese numero entero x: ");
		scanf("%f",&x);
		printf("ingrese numero entero y: ");
		scanf("%f",&y);
		printf("\nMENU: \n1 Suma\n2 Resta\n3 Multiplicación\n4 División\n5 Salir\nSeleccione una opción: \n" );
		scanf("%d",&opcion);
		
		switch(opcion) {
			case 1  : 
	      		printf("El resultado de la suma de %.4f y %.4f es: %.4f \n", x,y, x+y);

	      	break; 			
	   		case 2 :
	      		printf("El resultado de la resta de %.4f y %.4f es: %.4f \n", x,y, x-y);

	      	break; 
	  		case 3 :
	      		printf("El resultado de la Multiplicación de %.4f y %.4f es: %.4f \n", x,y, x*y);

	      	break; 
	  		case 4 :
	      		printf("El resultado de la División de %.4f y %.4f es: %.4f \n", x,y, x/y);
	      		
	      	break; 
	  		default : opcion=5;
	 
		}

	} while (opcion != 5);

	

}