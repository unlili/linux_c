#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>



int main(void)
{
    int fd = open("ps.out",O_WRONLY | O_CREAT | O_TRUNC,0644);
    if(fd < 0)
    {   
        perror("open fail");
        exit(1);
    }   

    dup2(fd,STDOUT_FILENO); //dup2(3,1)

    /*  
    0  std in                   0  std in
    1  std out                  1  fd
    2  std error   --dup2-->    2  std error
    3  fd                       3  fd
    dup2(3,1);  3  <--- 1 
    ps aux 原来是屏幕输出(stdout),现在是向文件fd输出
    */

    execlp("ps","ps","aux",NULL);//执行成功就不会回来了
    
    perror("execlp fail");
    exit(1);
    
    //close(fd) ???
    return 0;
}
