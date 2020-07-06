#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


void judgeFd(int fd) 
{
    if(fd == -1) 
    {   
        perror("open file");
        exit(1);
    }   
}


int main()
{
    int fd = open("english.txt",O_RDONLY);//open old file
    judgeFd(fd);
    int fd1 = open("newFile",O_CREAT | O_WRONLY,0664);//creat file
    judgeFd(fd);

    char buf[2048] = {0}; //creat buffer
    int count = read(fd,buf,sizeof(buf)); //read file
    if(count == -1) //if read file fail exit
    {
        perror("read");exit(1);
    }

    while(count)
    {
        // write data to another file
        int ret = write(fd1,buf,count);
        printf("write bytes %d\n",ret);
        //continue read file
        count = read(fd,buf,sizeof(buf));
    }

    close(fd);
    close(fd1);
    return 0;    
}
    
