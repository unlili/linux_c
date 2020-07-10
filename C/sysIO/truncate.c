#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>


int main(int argc ,char * argv[])
{
    if(argc < 2)
    {   
        printf("missing parameter");
        exit(1);
    }   

    long int a = strtol(argv[2],NULL,10);//char ---> int
    int ret = truncate(argv[1],a);
    if(ret == -1) 
    {   
        perror("truncate failed");
        exit(1);
    }   
    return 0;
}
