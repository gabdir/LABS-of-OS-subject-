#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	int k = 0;
	int **n =  malloc(10 * sizeof(int));

	while(k<10)
	{
		*(n+k) = malloc(2621440*sizeof(int));

		memset(*(n+k),0,2621440*sizeof(int));
		
		struct rusage* usage = malloc(sizeof(struct rusage)); 
		getrusage(RUSAGE_SELF, usage);

		if(errno == EFAULT)
		printf("Error: EFAULT\n");

		else if(errno == EINVAL)
		printf("Error: EINVAL\n");

		printf("Max: %ld\n",usage -> ru_maxrss);

		k++;
			sleep(1);
	}
	return 0;
}
