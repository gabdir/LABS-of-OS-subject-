#include <stdio.h>

void swap(int *x,int *y){
	int t;
	t = *x; 
	*x = *y;
	*y = t;
}

int main(int argc, char const *argv[])
{
	int a,b;
	scanf("%d", &a);
	scanf("%d", &b);
	swap(&a,&b);
	printf("%d ", a);
    printf("%d ", b);
	return 0;
}