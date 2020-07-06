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
    
    long int a = strtol(argv[2],NULL,8);
    
    int ret = chmod(argv[1],a);
    if(ret == -1)
    {   
        perror("chmod");
        exit(1);
    }
    
    return 0;
}
