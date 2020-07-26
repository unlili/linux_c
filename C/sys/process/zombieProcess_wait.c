#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(void)
{
    pid_t pid = fork();

    if(pid == 0)//child process
    {
        printf("this is child process pid = %u ppid = %u\n",getpid(),getppid());
        sleep(5);
        printf("child is die");
    }   
    else if( pid > 0)//parent process
    {   
        pid_t ret = wait(NULL);
        if(ret == -1){ perror("wait() func fail");exit(1); }
        while(1)
        {
            sleep(1);
            printf("this is parent process\n");
        }
    }
    else
    {
        perror("fork() func fail");
        exit(1);
    }



    return 0;
}
