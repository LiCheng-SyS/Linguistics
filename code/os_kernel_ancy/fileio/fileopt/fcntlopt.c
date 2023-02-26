#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(){
    int flags;
    if((flags=fcntl(STDIN_FILENO,F_GETFL))<0){
        perror("get flags");
        exit(1);
    } 
    //先获取当前的标志  ，再追加设置mode_t状态
    flags |=O_NONBLOCK;
    if((flags =fcntl(STDIN_FILENO,F_SETFL,flags))<0){
        perror(" fcntl set flags");
        exit(1);
    }
    char buf[10];
    ssize_t n;

    while(1){    
        n=read(0,buf,5);
        
        if(n>=0){
            //正常读到了数据
            break;
        }
        //这个错误经常出现在当应用程序进行一些非阻塞操作导致的报错
        if(errno!=EAGAIN){
            //如果不是EAGAIN 就是其他错误了
            perror("read");
            exit(1);
        }
        write(1,"try again\n",11);
        sleep(1);
    }

    write(1,buf,n);
    return 0;
}
