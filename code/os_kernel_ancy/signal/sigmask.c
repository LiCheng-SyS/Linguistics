#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <signal.h>


int main(){
    //阻塞信号屏蔽字->信号屏蔽集合
    sigset_t newset,oldset;
    //sigset_t 为初始化的
    //
    sigemptyset(&newset);//这是我的集合初始化置为空
    //在集合中增加阻塞信号
    sigaddset(&newset,SIGINT);  
    sigaddset(&newset,SIGSEGV);  
    //sigint 终端中断符
    //add sigint 至集合中
    //就是在设置阻塞
    sigprocmask(SIG_BLOCK,&newset,&oldset);//阻塞值个集合中所有信号
    raise(SIGSEGV);
    sleep(3);
    /*
    int n=10;
    while(n>0){
       sleep(1);
        printf("proc sleep ls\n");
        n--;
    }*/
    //这里将oldset 还原了
    sigprocmask(SIG_SETMASK,&oldset,NULL);
    return 0;
}
