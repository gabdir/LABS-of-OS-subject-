#include <stdio.h>
#include <stdint.h>
#include <string.h>

void reverse(char* str)
{
    int i, j;
    char temp;
    i=temp=0;
	j=strlen(str)-1;
    for (i=0; i<j; i++, j--)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    printf("%s\n",str);
}

int main(int argc, char const *argv[])
{
	char a[256];
	printf("%s\n", "Write some string: ");
	fgets(a,256,stdin);
	reverse(&a[0]);
	return 0;
}
