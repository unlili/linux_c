#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd; 
    int flag;

    char * p ="哈哈哈哈";
    char * q = "fighting fighting fighting ";

    fd = open("test.text",O_WRONLY);
    if(fd==-1)
    {   
        perror("open fail");
        exit(1);
    }   

    if(write(fd,p,strlen(p))==-1)//write to file
    {
        perror("write fail");
        exit(1);
    }

    flag = fcntl(fd,F_GETFL,0);//get file state flag
    if(flag == -1){perror("fcntl fail"); exit(1);}

    flag |= O_APPEND;
    if(fcntl(fd,F_SETFL,flag)==-1)//modify the file state to O_APPEND
    {
        perror("fcntl fail");
        exit(1);
    }

    if(write(fd,q,strlen(q))==-1)//write to file again 
    {
        perror("write fail");
        exit(1);
    }

    close(fd);

    return 0;
}
