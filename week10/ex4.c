#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

int main() {
  
  

  long inode[16];
  char files[16][30][16];

  int num = 0;
  int nn[16];
  memset(nn, 0, 16);
  
  DIR *dp = opendir("tmp");
  struct dirent *direct;

  if((direct = readdir(dp)) == NULL){
  	return -1;
  }

  while((direct = readdir(dp)) != NULL) {
    int i;
    for (i = 0; i < num; ++i)
      if(direct->d_ino == inode[i]) break;
    if (i == num)
      inode[num++] = direct->d_ino;
    strcpy(files[i][nn[i]++], direct->d_name);
  }

  for (int i = 0; i < num; ++i)
    if (nn[i] > 1) {
      printf("inode number: %ld\n", inode[i]);
      for (int j = 0; j < nn[i]; ++j)
        printf("%s\n", files[i][j]);
    }
}
