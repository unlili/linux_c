#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(void)
{
    pid_t pid = fork();
    int status;
    if(pid == 0)//child process
    {   
        printf("this is child process pid = %u ppid = %u\n",getpid(),getppid());
        sleep(40);
        printf("child is die\n");
        exit(111);
    }   
    else if( pid > 0)//parent process
    {   
        pid_t ret = wait(&status);

        if(ret == -1){ perror("wait() func fail");exit(1); }

        if(WIFEXITED(status))//宏函数参数为 int 不是 int *
        {
            printf("exit arguments is %d \n",WEXITSTATUS(status));
        }
        if(WIFSIGNALED(status))
        {
            printf("killed by %d signal \n",WTERMSIG(status));
        }
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
