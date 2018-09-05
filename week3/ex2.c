#include <stdio.h>

void bubble_sort(int a[],int n){
	int temp;
	 for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main(int argc, char const *argv[])
{
	int n; 
	int *a;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    bubble_sort(a,n);
	return 0;
}
