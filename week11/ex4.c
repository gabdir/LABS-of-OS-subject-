#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {

  int src = open("ex1.txt", O_RDONLY);
  int destination = open("ex1.memcpy.txt", O_RDWR | O_CREAT, S_IWRITE | S_IREAD);

  struct stat st;
  fstat(src, &st);
  size_t fsize = (size_t) st.st_size;

  char *src_reg = mmap((void*) NULL, fsize, PROT_READ, MAP_PRIVATE, src, 0);
  ftruncate(destination, fsize);

  char *dest_reg = mmap((void*) NULL, fsize, PROT_READ | PROT_WRITE, MAP_SHARED, destination, 0);
  memcpy(dest_reg, src_reg, fsize);
  
  close(src);
  close(destination);

  return 0;
}
