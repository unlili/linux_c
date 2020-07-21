#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
    pid_t pid = fork();

    if(pid == 0)
    {   
        while(1)
        {   
            printf("this is child pid = %u ppid %u .\n",getpid(),getppid());//父进程死后变成孤儿进程
            //!!!!   我好像就是个孤儿进程??  不对不对 , 我只是程序刚fork() 我就和父进程失去了联系 .... shit  2020年7月22日00:30:00
            sleep(1);
        }   
            
    }   
    else if(pid > 0 ) 
    {   
        printf("this is parent pid = %u \n.",getpid());
        sleep(6);
    }
    else
    {

        perror("fork fail");
        exit(1);
    }


    return 0;
}
