#include <stdio.h>
#include <unistd.h>

int main()
{
	char buffer[128];
	int rs = setvbuf(stdout, buffer, _IOLBF, 128);

	printf("H");
	sleep(1);
	printf("e");
	sleep(1);
	printf("l");
	sleep(1);
	printf("l");
	sleep(1);
	printf("o");
	sleep(1);
	printf("\n");
	
	return 0;	
}
