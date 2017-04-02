#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int length (const char *);

int main(int argc, const char *argv[])
{
    int len,i,j;
    char st[100];
    len = (int)sizeof(argv);
    strcpy(st, "");
    for (i = 1; i < len; ++i)
    {	
    	if(argv[i] !='\0'){
    		strcat(st,(char *)argv[i]);
    		strcat(st," ");
    	}else{
    		i = len;
    	}
    }
    strcat(st,"\n");
    j =length(st);
    write(1,(const char *)st, j);
    return 0;
}

int length (const char * d){
	int i;
	for (i = 0;d[i]!='\0'; i++);
	return i;
}
