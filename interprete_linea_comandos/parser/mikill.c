#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char **argv){	
    if (argc < 2){
        printf("usage: ./kill PID");
        return -1;
    }
    int signal = atoi(argv[1]);
    pid_t pid = atoi(argv[2]);
    
    if(signal == -9 || signal == -7 || signal == 0 || signal == -1 || signal == -2 || signal == -3){
    	kill(pid , SIGKILL);
    }
    else{
    	printf("Señal invalida\n");
    }
    return 0;
}