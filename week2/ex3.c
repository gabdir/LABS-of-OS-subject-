#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n; 
	scanf("%d",&n);
	int height=n; 
	int width=2*n-1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j<height; j++)
		{
			putchar(' ');
		}
		for (int k = 0; k<2*i-1; k++)
		{
			putchar('*');
		}
		printf("\n");
		height--;
	}
	return 0;
}