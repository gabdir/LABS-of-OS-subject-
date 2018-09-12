#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void scan(char *command){
	scanf("%s", command);
}

void pr(){
	printf("$ ");
}


int main(int argc, char const *argv[]){
	char command[50];
	while (1) {
	pr();
	scan(command);
	system(command);
	}
	return 0;
}