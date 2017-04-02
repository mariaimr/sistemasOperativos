#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int factorial(int d);
int main(int argc, char const *argv[])
{
	pid_t h1,h2;
	int status;

	h1 = fork();
	if(h1<0){
		printf("ERROR\n");
		exit(-1);
	}
	else{
		if (h1==0)
		{	int i;
			for (i = 0; i < 10; ++i)
			{
				printf("HIJO1 FACTORIAL DE %d= %d\n",i,factorial(i));
			}
			exit(0);
		}
		else{
			h2 =fork();
			if(h2<0){
				printf("ERROR\n");
				exit(-1);
			}
			else{
				if (h2==0)
				{	int i;
					for (i = 0; i < 10; ++i)
					{
						printf("HIJO2 FACTORIAL DE %d= %d\n",i,factorial(i));
					}
					exit(0);
				}
			}
		}
	}
	wait(&status);
	wait(&status);
	return 0;
}

int factorial(int d){
	if(d==0)return 1;
	int fact = d * factorial(d-1);
	return fact;
}