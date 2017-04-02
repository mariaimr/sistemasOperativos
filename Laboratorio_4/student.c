#include <stdio.h>

// Definición de la estructura
struct ​student {
 char ​name[40];
 int ​numStudent;
 float ​grade;
};

int main()
{
	// Inicialización de una nueva 
	struct ​student student1 = {“Fulano”, “5”, “2.1”};

	struct ​student *ptrStudent;
	ptrStudent = &student1;

	printf("nombre: %s\n", ptrStudent->name);
	return 0;
}