#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SHMSZ     27

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

  /*Se requiere el segmento llamado "1234" creado por el
	servidor   
*/ 
    key = 1234;

    /* Ubica el segmento */
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

   /* Se adhiere al segmento para poder hacer uso de él */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

   /* Lee lo que el servidor puso en la memoria */
    for (s = shm; *s != NULL; s++)
        putchar(*s);
    putchar('\n');

   /* Finalmente, cambia el calor del primer carácter indicando
	que ha leído el segmento */
    *shm = '*';

    exit(0);
}