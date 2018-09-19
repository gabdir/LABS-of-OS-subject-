#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 

void *thread_print(void *arg) 
{ 
    int *id = (int *)arg;
    printf("Thread ID: %d\n", *id); 
    printf("%s\n", "OS");
} 

int main(int argc, char const *argv[])
{	
	int n; 
	scanf("%d",&n);
	pthread_t thread_id;
	pthread_t thread2[n]; 
    for (int i = 0; i < n; ++i)
    {
    	pthread_create(&thread2[i], NULL, thread_print, (void *)&thread2[i]); 
    }
    for (int i = 0; i < n; ++i)
    {
    	pthread_join(thread2[i],NULL);
    }
    for (int i = 0; i < n; i++) {
        pthread_create(&thread_id, NULL, thread_print, (void *)&thread_id); 
    	pthread_join(thread_id, NULL); 
    }
	pthread_exit(NULL);
	return 0;
}