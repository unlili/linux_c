#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>


int get_num(char * rootPath)
{
    struct dirent * ptr = NULL;
    int total = 0;
    char path[1024];
    DIR * dir = opendir(rootPath);


    if(dir == NULL)
    {   
        perror("opendir fail");
        exit(1);
    }   
    
    while((ptr=readdir(dir)) != NULL)
    {   
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..") == 0 ) 
        {
          //. and .. file not count
            continue;
        }
        if(ptr->d_type == DT_DIR)
        {
            sprintf(path,"%s/%s",rootPath,ptr->d_name);
            total += get_num(path);
        }
        if(ptr->d_type == DT_REG) ++total;
    }

    closedir(dir);
    return total;
}



int main(int argc,char * argv[])
{

    if(argc < 2)
    {
        perror("miss file");
        exit(1);
    }

    printf("file num is %d\n",get_num(argv[1]));

    return 0;
}
