#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
  /*
  unlink删除的文件在打开时不会被删除,但是最终会被删除.
  
  
  */
int main()
{
    int fd = open("tempfile",O_CREAT|O_RDWR,0666);
    if(fd == -1) 
    {   
        perror("open fail");
        exit(1);
    }   

    //delete temporary file
    int ret = unlink("tempfile");
    write(fd,"hello\n",6);//write in temp file
    lseek(fd,0,SEEK_SET);//file pointer is set to start

    char buf[24] = {0};
    int len = read(fd,buf,sizeof(buf));// read file
    write(1,buf,len);//print screen

    //close file
    close(fd);
    return 0;
}
