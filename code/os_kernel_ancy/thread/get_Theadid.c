#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<errno.h>
#include<sys/types.h>


pthread_t  tid;
void printid(char *);
//外接动态库
void *thr_fn(void *arg){
    printid((char *)arg);
    return NULL ; //(void)*0
}
void printid(char *tip){
    printf("arg :%p\n",&tip);
    pid_t pid= getpid();//当前进程
    tid=pthread_self();//返回当前进程的线程id
    printf(" %s pid:u%u  tid:%u (%p)\n",tip,pid,tid,tid);
    return;
}
int main(){
    pthread_t ntid;
    int ret;
    ret=pthread_create(&ntid,NULL,thr_fn,(void*)" new thead");
    if(ret){
        printf("creat thread %s\n",strerror(ret));
        exit(1);
    }
    //由于主线程退出 新线程就会被终结 所以需要等待一下
    sleep(1);
    printid(" main thread\n");
    return  0;
}
