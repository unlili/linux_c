#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(void)
{
    pid_t pid = fork();



    if(pid == -1) 
    {   
        perror("fork fail");
        exit(1);
    }   
    else if(pid > 0)//父进程返回子进程的pid
    {   
        sleep(2);   
    }   
    else if(pid == 0)
    {   
        execlp("ls","ls","-l","-a","-h",NULL);
        //execl("/bin/ls","ls","-l","-a","-h",NULL);
    }

    return 0;
}
