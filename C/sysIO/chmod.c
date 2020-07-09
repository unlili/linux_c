#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc,char * argv[])
{   
    if(argc < 2)
    {   
        printf("missing parameter");
        exit(1);
    }
    //  把一个字符串变成8进制整型   '777' --> int 777
    long int a = strtol(argv[2],NULL,8);//修改参数argv[1]的权限修改为agrv[2]
    
    int ret = chmod(argv[1],a);
    if(ret == -1)
    {   
        perror("chmod");
        exit(1);
    }
    
    return 0;
}
