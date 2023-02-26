#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>


//将  a文件作为标准输入文件，如果不存在则创建,作为标准输出,调upper读数据再转大写写入
//tty 0的位子进行重定向 (标准输入)
int main(int argc,char ** argv){
    if(argc< 2){
        perror("fail cmd");
        exit(1);
    }
    int fd=open(argv[1],O_RDONLY);
    if(fd<0){
        perror("open fail");
        exit(1);
    }
    //后面指向前面的 把文件复制过来
    //类似于调度重定向  将文件中拷贝后重定向到终端
    dup2(fd,0);
    close(fd);
    //权限
    fd=open(argv[2],O_WRONLY| O_CREAT ,0644);
    if(fd<0){
        perror("open fail2");
        exit(1);
    }
    //标准输出流
    dup2(fd,1);
    close(fd);
    //转大写的程序
    execl("./upper","./upper",NULL);
    perror("execl fail");
    exit(1);
    return 0;
}
