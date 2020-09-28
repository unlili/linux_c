### c语言文件缓冲区

`fflush()`  :  **刷新缓冲区**  



#### 什么情况下缓冲区会写入硬盘

1. 调用fflush()

2. 缓冲区已满

3. * fclose();

   * return;

   * exit();

     

**c语言在读写文件时需要处理内存与硬盘读取速度的问题,所有的文件先写入缓冲区,缓冲区满了才会写入到硬盘中,linux系统函数并没有提供缓冲区,需要自己提供缓冲区.**

**注意文件读写指针位置**

---

### linux文件描述符



**32位操作系统,在每一个linux进程运行时都会分配一个0~4G的虚拟地址空间,**

> **3~4G  linux kernel  :  PCB进程控制块** 
>
> > **文件描述符表 : 一个1024大小的数组,对应1024个文件,每打开一个文件就对应一个文件描述符表**
> >
> > **默认  0  STDIN_FILENO  --  标准输入**
> >
> > **默认  1  STDOUT_FILENO  --  标准输出**
> >
> > **默认  2  STDERR_FILENO  --  标准错误**
> >
> > **前三个默认打开状态**

#### **0~3G 用户空间**

**环境变量**

**命令行参数**

**栈空间**

**共享库**                                               ------> C标准库 linux系统IO函数

**堆空间**

**.bss(未初始化全局变量)**                  ------> ELF

**.data(已初始化全局变量)**                ------> ELF

**.text(代码段,机器指令)**                    ------> ELF

**受保护地址 (0~4k)**



---

### 系统函数

#### **`open()`**

```c++
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode)
int creat(const char *pathname, mode_t mode);
```

**`flags `**  :  打开方式  

* O_RDONLY   只读
* O_WRONLY  只写
* O_RDWR       读写

**`mode_t`**  :  附加选项

* O_CREAT        文件权限  *(实际权限为指定权限与本地掩码取反后 , 在与)*
* O_TRUNC       将文件截断为0  *(清空文件)*
* O_EXCL
* O_APPEND



```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd1 = open("hello",O_RDWR | O_CREAT,0777);//创建一个权限为777的hello
    if(fd1 == -1) {perror("open fail : "); exit(1); }
    
    int fd2 = open("hello",O_RDWR | O_CREAT | O_EXCL,0777);//判断文件是否存在
    if(fd2 == -1) {perror("open fail : "); exit(1); }
    
    int fd3 = open("hello",O_RDWR | O_TRUNC); //文件截断为0
    if(fd3 == -1) {perror("open fail : "); exit(1); }
    
    int ret = close(fd); if(ret == -1) {perror("close() fail : "); exit(1); }
    return 0;
}
```



#### **`read()`    `write()`**

```C
#include <unistd.h>
ssize_t read(int fd,void * buf,size_t count); //从fd读count个字节到buf缓冲区
ssize_t write(int fd,const void * buf,size_t count); // 向fd所引用的文件中,写入buf里count个字节
```

**read()返回值**

* 0    文件读取完毕
* -1   失败 
* 大于0  读取字节数



#### **`lseek`**

* 获取文件大小
* 移动文件指针
* 文件拓展

```c
#include<sys/types.h>
#include<unistd.h>

off_t lseek(int fd,off_t offset,int whence);//
```

**`whence`**

* SEEK_SET
* SEEK_CUR
* SEEK_END

#### **`close`**

---

### 一些代码

```c
file` 文件名   : 查看文件类型
man 2 lseek
```

















