#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern char ** environ;


int main(void)
{
    int i=0;

    do{ 
    printf("%s\n",environ[i]);
    ++i;
    }while(environ[i]);


    return 0;
}
