#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{	
	pid_t h2,h3,h34,h35;
	int status;
	h2 = fork();
	if (h2<0)
	{
		printf("Error\n");
		exit(-1);
	}
	else{
		if(h2==0){
			printf("SOY HIJO2: El PID de mi padre es:%u\n", getppid());
			printf("SOY HIJO2: Mi PID es: %u\n",getpid());
			exit(0);
		}
		else{
			h3=fork();
			if(h3<0){
				printf("Error\n");
				exit(-1);
			}
			else{
				if(h3==0){
					printf("SOY HIJO3: El PID de mi padre es:%u\n", getppid());
					printf("SOY HIJO3: Mi PID es: %u\n",getpid());
					h34=fork();
					if (h34<0)
					{
						printf("Error\n");
						exit(-1);
					}
					else{
						if (h34==0)
						{
							printf("SOY HIJO 4 de papa 3: El PID de mi padre es:%u\n", getppid());
							printf("SOY HIJO 4 de papa 3: Mi PID es: %u\n",getpid());
							exit(0);
						}
					}
					h35=fork();
					if (h35<0)
					{
						printf("Error\n");
						exit(-1);
					}
					else{
						if (h35==0)
						{
							printf("SOY HIJO 5 de papa 3: El PID de mi padre es:%u\n", getppid());
							printf("SOY HIJO 5 de papa 3: Mi PID es: %u\n",getpid());
							exit(0);
						}
					}
					wait(&status);
					wait(&status);
					exit(0);
				}
			}
			wait(&status);
			wait(&status);
			printf("SOY PAPI: El PID de mi padre es:%u\n", getppid());
			printf("SOY PAPI: Mi PID es: %u\n",getpid());
			system("pstree");

		}
	}
	
	return 0;
}