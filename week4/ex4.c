#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_WORD 10
#define MAX_CHAR 100

void remove_end(char line[]){
  int i = 0;
  while(line[i]!='\n')
    i++;

  line[i] = '\0';
}

void read_line(char line[]){
  char* ret = fgets(line,MAX_CHAR,stdin);
  remove_end(line);
  if(strcmp(line,"exit") == 0 || ret == NULL)
    exit(0);
}

int process_line(char* args[], char line[]){
  int i = 0;
  args[i] = strtok(line," ");
  if(args[i]==NULL)
  {
    return 1;
  }
  while(args[i]==NULL){
    i++;
    args[i] = strtok(line," ");
  } 
  return 1; 
}

int read_parse(char* args[],char line[]){
      read_line(line);
      process_line(args,line);
}

void pr(){
  printf("$ ");
}


int main(int argc, char const *argv[]){
	 char* args[MAX_WORD];
   char line[MAX_CHAR];

   while(1){
    pr();
    read_parse(args,line);
    pid_t  pid = fork();
    if(pid==0){
      execvp(args[0],args);
    }
    else {
      waitpid(pid,NULL,0);
    }
    return 0;
  }

}


