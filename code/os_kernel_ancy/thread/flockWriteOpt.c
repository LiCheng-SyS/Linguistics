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
    int fd=open("./fockopt.txt",O_WRONLY); 
    if(!~fd){
        perror("open fail");
        exit(1);
    }
    struct  stat sta;
    fstat(fd,&sta);
    struct  flock lock;
    lock.l_type=F_WRLCK;
    lock.l_pid=getpid();
    lock.l_whence=SEEK_SET;//从起始位子
    lock.l_start=0;
    lock.l_len=sta.st_size;
    printf(" get pid=%d\n",lock.l_pid);
    while(fcntl(fd,F_SETLK,&lock)<0)    //
    {
        perror("fcntl fail");
        struct flock lock_1;
        lock_1=lock;
        lock_1.l_type=F_WRLCK;
        //本意是上写锁
        //获取当前锁得状态
        //得出问题的原因
        fcntl(fd,F_GETLK,&lock_1);
        switch(lock_1.l_type){
        case F_UNLCK:
            printf("get no lock\n");
            break;
        case F_RDLCK:
            printf("get read lock of pid=%d\n",lock_1.l_pid);            
            break;
        case F_WRLCK:
            printf(" get write lock of pid=%d\n",lock_1.l_pid);
            break;
        }    
        sleep(1);
    }
    printf("set  write lock succ\n");
    getchar();
    close(fd);
    return 0;
}
