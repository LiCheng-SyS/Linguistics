#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


int main (int argc,char *argv[]){
    if(argc <2){
        printf("user cmd filename\n");
        return -1;
    }

    printf("%s\n",argv[1]);
    int fd=open(argv[1],O_RDWR | O_CREAT | O_TRUNC,0777);//如果没有则创建和 w+绑定：拿宏替换也是可以的    
    printf("%d\n",errno);//errno 捕获异常并转换
    printf("%s\n",argv[1]);
    if(fd<0){
        perror("OPEN ");
        exit(-1); //区别 -1 结束main 函数碰到 exit就直接结束了 
        return -1;
    }else{
        printf("验证是否最小的描述符%d\n",fd);
    }
   // close(fd);

    int fd1=open(argv[2],O_RDWR | O_CREAT | O_TRUNC,0777);//如果没有则创建和 w+绑定：拿宏替换也是可以的    
    printf("%d\n",errno);//errno 捕获异常并转换
    printf("%s\n",argv[2]);
    if(fd<0){
        perror("OPEN 2");
        exit(-1); //区别 -1 结束main 函数碰到 exit就直接结束了 
        return -1;
        return 0;
    }else{
       printf("验证是否最小的描述符%d\n",fd1); 
    }
    int fd3=open(argv[3],O_RDWR | O_CREAT | O_TRUNC,0777);//如果没有则创建和 w+绑定：拿宏替换也是可以的    
    printf("%d\n",errno);//errno 捕获异常并转换
    close(fd);
    printf("%s\n",argv[3]);
    if(fd<0){
        perror("OPEN 3");
        exit(-1); //区别 -1 结束main 函数碰到 exit就直接结束了 
        return -1;
        return 0;
    }else{
        printf("验证是否最小的描述符%d\n",fd3);
    }
    close(fd1);
    close(fd3);
    return 0;
}
