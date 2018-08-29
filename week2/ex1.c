#include <limits.h>
#include <stdio.h>
#include <float.h>
int main(int argc, char const *argv[])
{
	int a;
	float b;
	double c; 
	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;
	printf("%i\n",a);
	printf("%f\n",b);
	printf("%f\n",c);
	return 0;
}