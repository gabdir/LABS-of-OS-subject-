#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int sign)
{
    if (sign == SIGUSR1)
        printf("received SIGUSR1\n");
    else if (sign == SIGKILL)
        printf("received SIGKILL\n");
    else if (sign == SIGSTOP)
        printf("received SIGSTOP\n");
}

int main(void)
{
    if (signal(SIGUSR1, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGUSR1\n");
    if (signal(SIGKILL, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGKILL\n");
    if (signal(SIGSTOP, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGSTOP\n");
    while(1) 
        sleep(1);
    return 0;
}