#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	char *src = "This is a nice day";
	
	int fd = open("ex1.txt",O_RDWR,0);
	if (fd<0) { perror("ex1.txt open"); exit(EXIT_FAILURE); };

	int src_size = strlen(src);
	ftruncate(fd, src_size);

	char *addr;
	addr = mmap((void*) NULL, src_size, PROT_READ | PROT_WRITE| PROT_EXEC, MAP_SHARED, fd, 0);
	
	strcpy(addr, "This is a nice day");

	close(fd);

	return 0;
}
