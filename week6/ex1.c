#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
      int pip[2],nbytes;
      char    string[] = "Kamil my friend!\n";
      char    output[100];
      pipe(pip);
      write(pip[1], string, (strlen(string)+1));
      nbytes = read(pip[0], output, sizeof(output));
      printf("String: %s", output);

}