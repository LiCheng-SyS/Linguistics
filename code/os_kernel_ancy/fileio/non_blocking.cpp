#include<vector>
#include<iostream>
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

using namespace std;

int main(int grgc,char *argv[]){
    char buf[10];
    //非阻塞
    int fd= open("/dev/tty",O_RDONLY | O_NONBLOCK);
    if(fd<0){
        perror("Open /dev/tty");
        exit(1);
    }    
    //打开
    ssize_t n;
    n=read(fd,buf,10);
    int cnt=10; 
    while(1){
        n=read(fd,buf,10);
        if(~n){//按位取反
            //读成功了
            printf("read %dbytes\n",n);
            write(STDOUT_FILENO,buf,n);
            break;
        }
        if(errno !=EAGAIN){
            //这是真报错了  什么都没读到
            perror("READ /dev/tty");
            exit(1);
        }
        //非阻塞读的报错
        write(STDOUT_FILENO,"Try Try?\n",9);
        sleep(1);
        cnt--;
    }

    close(fd);
    return 0;
}


