#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int n; 

	scanf("%d",&n);

	int *arr = calloc(n, n * sizeof(int));

	for (int i = 0; i < n; ++i)
		*(arr+i) = i;

	for (int i = 0; i < n; ++i)
		printf("%d ", *(arr+i));
	
	free(arr);

	return 0;
}