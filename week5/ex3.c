#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>


time_t start;
int i = 0;
pthread_mutex_t mutex;
pthread_cond_t condc, condp;
char reo[100];
int count = 0;

void *consum(void *argument)
{
 while (1) { 
  pthread_mutex_lock(&mutex);
  if (count == 0){
    pthread_cond_wait(&condc, &mutex);
  }
  reo[count] = 'c';
  count = count - 1;
  if (count == 100 - 1){
   pthread_cond_signal(&condp);
   pthread_mutex_unlock(&mutex);
  }
 }
}

void *produc(void *argument)
{

 while (1) { 
  pthread_mutex_lock(&mutex);
  
  if (count == 100){
   pthread_cond_wait(&condp, &mutex);
  }
  reo[count] = 'p';
  count = count + 1;
  time_t end = time(NULL);
  double fraction = (double)(end - start);

  if(fraction > i*60){
   printf("execution time:%f\n", ((double)(end - start)));
   i++;
  }

  if (count == 1){
   pthread_cond_signal(&condc);
   pthread_mutex_unlock(&mutex);
  }
 }
}




int main(int argc, char const *argv[]){
 
 start = time(NULL);
 pthread_t pro, con;
 pthread_mutex_init(&mutex, 0);
 pthread_cond_init(&condc, 0);
 pthread_cond_init(&condp, 0);
 pthread_create(&con, 0, consum, 0);
 pthread_create(&pro, 0, produc, 0);
 pthread_join(pro, 0);
 pthread_join(con, 0);
 pthread_cond_destroy(&condc);
 pthread_cond_destroy(&condp);
 pthread_mutex_destroy(&mutex);
 
 return 0;

}