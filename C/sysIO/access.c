#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc ,char * argv[])
{
    if(argc < 2)
    {   
        printf("a.out filename");
        exit(1);
    }

    int arr[3] = {0};

    arr[0] = access(argv[1],R_OK);
    arr[1] = access(argv[1],W_OK);
    arr[2] = access(argv[1],X_OK);

    if(arr[0] == -1 || arr[1] ==-1 || arr[2] ==-1)
    {   
        perror("access");
        exit(1);
    }
    char str[3];
    str[0] = (arr[0] == 0 ? 'r':'-');
    str[1] = (arr[1] == 0 ? 'w':'-');
    str[2] = (arr[2] == 0 ? 'x':'-');
    printf("\n");
    printf("%s\n",str);
    printf("\n");

    return 0;
}
