#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include<sys/wait.h> 

int main(void)
{
      int pip[2],new;
      pid_t childpid;
      char string[] = "Kamil my friend!\n";
      char output[80];
      pipe(pip);
      childpid = fork();
      if(childpid==-1){
         perror("fork");
         exit(1);
      }
      if(childpid > 0){
        close(pip[0]);
        write(pip[1], string, (strlen(string)+1));
        close(pip[1]); 
        wait(NULL);
      }
      else{
         close(pip[1]);
         new = read(pip[0], output, sizeof(output));
         printf("String: %s", output);
         close(pip[0]);
         exit(0); 
      }
      
    return 0; 
}