#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <errno.h>
#include <unistd.h>
int main(int argc,char **argv){
    if(argc<2 ){
        printf("use:cmd staus fd\n");
        exit(1);
    }
    //解析文件描述符的各项权限
    int falgs;
    if((falgs=fcntl(atoi(argv[1]),F_GETFL))<0)
    {
        perror(" fcntl get flags");
        exit(1);
    }
    switch(falgs & O_ACCMODE){
    case O_RDONLY:
        printf("read only");
        break;
    case O_WRONLY:
        printf(" write only ");
        break;
    case O_RDWR:
        printf(" read write");
        break;
    default:
        printf(" invalid access mode\n");
    }
    if(falgs & O_APPEND){
        printf(" ,appen ");
        //判断是否某个权限
    }
    if(falgs & O_NONBLOCK){
        printf(" nonblock ");
    }
    //printf("O_NONBLOCK =%lu\n",O_NONBLOCK);
    putchar(10);
    // 16进制
    /*
       printf("flags =%#x\n",falgs);
       printf("O_RDONLY =%#x\n",O_RDONLY);
       printf("O_WRONLY =%#x\n",O_WRONLY);
       printf("O_RDWR =%#x\n",O_RDWR);
       printf("O_APPEND =%#x\n",O_APPEND);
       printf("O_NONBLOCK =%#x\n",O_NONBLOCK);
    //32770
    printf("O_ACCMODE =%#x\n",O_ACCMODE);

*/
    return 0;    
}
