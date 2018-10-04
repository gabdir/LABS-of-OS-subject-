#include <stdio.h>
#include <stdlib.h>

int * rrealloc(int *ptr,int old,int new);

int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}

int main(int argc, char const *argv[])
{
	int *array = calloc(5,5*sizeof(int));

	for (int i = 0; i < 5; ++i)
	{
		*(array+i) = 100;
		printf("%d ", *(array+i));
	}
	
	printf("\n");

	array = rrealloc(array,5,15);

	for (int i = 0; i < 15; ++i)
	{
		printf("%d ",*(array+i));
	}

	return 0;
}

int * rrealloc(int *ptr,int old,int new){
	
	int *new_ptr;

	if(ptr == NULL){
		
		new_ptr = malloc(sizeof(new));
	}
	else if(new == 0){

		free(ptr);
		return ptr;
	}
	else{
		
		new_ptr = malloc(sizeof(new));

		int minn = min(new,old);

		if(ptr != NULL){


			for (int i = 0; i < minn; ++i)
			{
				*(new_ptr + i) = *(ptr+i);
			}
		}
	}

	return new_ptr;
}