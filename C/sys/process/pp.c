
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc , char * argv[])
{
    if(argc < 2)
    {   
        perror("miss parameter");
        exit(1);
    }   
    printf("argc=%d\n",argc);   
    for(int i=0;i<argc;++i)
    {   
        printf(" %s\n",i,argv[i] );
    }   
    printf("child process over\n");
    return 0;
}
