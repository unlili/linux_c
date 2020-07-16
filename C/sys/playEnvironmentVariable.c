#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
char *getenv(const char *name);
int setenv(const char *name, const char *value, int overwrite);
int unsetenv(const char *name);
*/
static unsigned int a = 1;
//print a environment variable
void printEnv(const char * name)
{
    printf("%d   %s , %s\n\n",a++,name,getenv(name));
}


int main(int argc,char * argv[])
{
    if(argc < 2)
    {   
        perror("miss input parameter");
        exit(1);
    }   
    const char * name = argv[1];
    printEnv(name);

    setenv(name,argv[2],1);  //set a environment variable
    printEnv(name);

    unsetenv(name);  //delete this environment variable
    printEnv(name);
}
