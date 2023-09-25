#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
        char *cmd1 = argv[1];
        char *cmd3 = argv[3];
	int fd[2];
	pipe(fd);	
	int ch1 = fork();
	int gc1;

        if(ch1 == 0)	//Child and Grandchild
        {
		int gc1 = fork();
		if(gc1==0)	//Grandchild
		{
                        close(fd[1]);   
                        dup2(fd[0], 0); 
                        close(fd[0]);   

                        execlp(cmd3,cmd3, (char*)NULL);
		}
		else	//Child
		{
			close(fd[0]);
                        dup2(fd[1], 1);
                        close(fd[1]);

                        execlp(cmd1,cmd1,(char*)NULL);
		}       
        }
        else	//Parent
        {
		close(fd[0]);
		close(fd[1]);
		waitpid(ch1,NULL,0);
		waitpid(gc1,NULL,0);
                printf("++++\n");
        }

}

