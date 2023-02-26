#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<semaphore.h>
#include<time.h>
#include<error.h>
int main(){
    int fd=open("./fockopt.txt",O_RDONLY); 
    if(!~fd){
        perror("open fail");
        exit(1);
    }
    struct  stat sta;
    fstat(fd,&sta);
    struct  flock lock;
    lock.l_type=F_RDLCK;
    lock.l_pid=getpid();
    lock.l_whence=SEEK_SET;//从起始位子
    lock.l_start=0;
    lock.l_len=sta.st_size;
    printf(" get pid=%d\n",lock.l_pid);
    if(fcntl(fd,F_SETLK,&lock)<0)//得到一个锁
    {
        perror("fcntl fail");
        exit(1);
    }else{
        printf(" add read lock succ");
    }
    sleep(10);
    close(fd);
    return 0;
}
