#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	char *cmd = argv[1] ;
	char **parm = argv + 1;
	if(fork() == 0)
	{
		execvp(cmd, parm);
	}
	else
	{
		wait(NULL);
		printf("++++\n");
	}

}
