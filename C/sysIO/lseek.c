#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int fd = open("aa",O_RDWR);//open file    
    if(fd == -1){ perror("\n"); printf("\n"); exit(1);}
    
    int ret0 = lseek(fd,0,SEEK_END);//get file length
    printf("file size = %d\n",ret0);

    int ret1 = lseek(fd,2000,SEEK_END);// file expand
    printf("file size = %d\n",ret1);
    
    write(fd,"a",1);//随便写点实现扩展

    close(fd);
    return 0;
}
