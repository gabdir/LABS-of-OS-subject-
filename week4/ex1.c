#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
    pid_t n;
    pid_t pid;
    n = getpid();
    pid=fork();
    if(pid<0)
    {
        printf("\n Error ");
    }
    else if(pid==0){
        n = getpid();
        printf("Hello from child [%d - %d]\n",pid, n);
    }
    else{
       printf("Hello from parent [%d - %d]\n",pid, n);
    }
    
}