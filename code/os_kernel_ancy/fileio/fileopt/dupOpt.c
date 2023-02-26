#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
#include <error.h>
#include <unistd.h>
int main(){
    int fd,save_fd;
    if((fd=open("hello.txt",O_RDWR))<0){
        perror("open");
        exit(1);
    }
    //保存fd
    //把标准输出保存 复制给保存的新的fd
    save_fd = dup(1);
    //4
    printf("fd =%d",fd);
    dup2(fd,1); //1 ->指向了3
    close(fd);
    write(1,"hello",5);
    dup2(save_fd,1);
    write(1,"12345",10);
    close(save_fd);
    return 0;
}
