/*
	Cuantos estudiantes tiene?,-----> ¿Quiere ingresar los datos desde 0(con w) o quiere adicionar nuevos datos a un archivo existente(con a)?
	de Cada estudiante se recibira un ID y 4 notas entre 0 y 5 con dos numeros decimales
	Calcular promedio de la nota
	imprimir dentro de un archivo de texto: "Profesor:
											notas de geografia: 
											ID nota1 nota2 nota3 nota4  promedio
											1    5     5     5     4       4.75   
	 "
*/
#include <stdio.h>
#include <stdlib.h>

const char FILE_NAME[]= "archivo.txt";
typedef struct{
	int id;
	float nota1;
	float nota2;
	float nota3;
	float nota4;

}estudiante; // se crea una estructura estudiante

float promedio(estudiante est); // se declara una función promedio

int main(void){
	char opcion;
	int i, cantidadEst;
	estudiante student;
	float prom;

	printf("Si quiere ingresar los datos desde 0 digite s, De lo contario escriba n: \n"); // se pide la opción a trabajar
	scanf("%s", &opcion);
	FILE *in_file;
	if (opcion == 's') // si se quiere iniciar desde 0 entonces
	{	in_file = fopen(FILE_NAME, "w"); // fopen= retorna un apuntador hacia el  archivo para escribir uno nuevo
		fprintf(in_file, "Profesor: GIRAFALES\nNotas de: GEOGRAFIA \n");
		fprintf(in_file, "ID\tNota 1\tNota 2\tNota 3\tNota 4\tPROMEDIO\n");
		
	}
	else{ // si se quiere trabajar en un archivo existente
		in_file = fopen(FILE_NAME, "a"); // fopen= retorna un apuntador hacia el  archivo para escribir
	}
	if(in_file==NULL){ //no existe el archivo
		printf("NO PUEDE ABRIRSE EL ARCHIVO: %s\n",FILE_NAME );
		exit(8);
	}
	if(!ftell(in_file)){ // si el archivo esta vacio
		fprintf(in_file, "Profesor: GIRAFALES\nNotas de: GEOGRAFIA \n");  // se crea la cabecera
		fprintf(in_file, "ID\tNota 1\tNota 2\tNota 3\tNota 4\tPROMEDIO\n");
	}
	
	printf("¿Cuantos estudiantes desea ingresar?: \n");
	scanf("%d", &cantidadEst); // se lee la cantidad de estudiantes

	for (i = 0; i < cantidadEst; ++i) // for para pedir cada uno de los datos de la estructura estudiante
	{
		printf("Identificacion del estudiante #%d:  \n", i+1);
		scanf("%d",&student.id);
		printf("Ingrese la nota número 1 del estudiante %d:  \n",student.id);
		scanf("%f",&student.nota1);
		printf("Ingrese la nota número 2 del estudiante %d:  \n",student.id);
		scanf("%f",&student.nota2);
		printf("Ingrese la nota número 3 del estudiante %d:  \n",student.id);
		scanf("%f",&student.nota3);
		printf("Ingrese la nota número 4 del estudiante %d:  \n",student.id);
		scanf("%f",&student.nota4);
		prom= promedio(student);
		fprintf(in_file,"%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",student.id, student.nota1,student.nota2,student.nota3,student.nota4, prom); // imprime en el archivo.txt 

	}
	fclose(in_file); // se cierra el archivo

	return 0;
}
float promedio(estudiante est){ // funcion promedio
	float suma;
	float promedio;
	suma = est.nota1 +est.nota2 +est.nota3 +est.nota4;
	promedio= suma/4;
	return promedio;
}




