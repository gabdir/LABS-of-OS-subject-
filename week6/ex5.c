#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define TRUE 1

pid_t p1, p2, tem;
int i = 0;

void sighan(int signumb) {
    if (signumb == SIGTERM) {
        if (p1 == p2) {
            printf("SIGTERM");
        }
    }
}

int main() {
    signal(SIGTERM, sighan);
    p1 = getpid();
    fork();
    p2 = getppid();
    tem = getpid();
    while (TRUE) {
        if (i == 10) {
            kill(tem, SIGTERM);
            return 0;

        } else {
            printf("I'm alive\n");
            sleep(1);
            i++;
        }
    }
    return 0;
}