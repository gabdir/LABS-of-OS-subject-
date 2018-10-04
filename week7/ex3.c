#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	
	srand(time(NULL));

	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	
	int* a1 = calloc(n1,n1*sizeof(int));

	for(int i = 0; i < n1; i++){

		*(a1 + i) = 100;
		printf("%d ",*(a1 + i));
	}
	
	printf("\n");
	
	printf("\nEnter new array size: ");
	int n2 = 0;
	scanf("%d",&n2);

	
	a1 = realloc(a1,n2);

	if(n2 > n1){

		for (int i = n1; i < n2; ++i)
			*(a1+i) = 0;
	}

	
	

	for(int i = 0; i < n2;i++)
		printf("%d ",*(a1 + i));

	printf("\n");
	
	
	
	return 0;
}
