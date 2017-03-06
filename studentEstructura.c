#include <stdio.h>

struct student{
	char name[50];
	int numStudent;
	float grade;
};

int main()
{
	struct student student1= {"fulano",5,2.1};

	struct student *ptrStudent;
	ptrStudent= &student1;

	printf("nombre: %p\n", ptrStudent);
	return 0;
}