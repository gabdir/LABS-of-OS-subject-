#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	int k = 0;
	int **n =  malloc(10 * sizeof(int));

	while(k<10)
	{
		*(n+k) = malloc(2621440*sizeof(int));

		memset(*(n+k),0,2621440*sizeof(int));
		k++;

		sleep(1);
	}
	return 0;
}
