#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <signal.h>
void print_sig(const sigset_t *set){
    int i;
    for(i=1;i<32;i++){
        //判断是否为set的成员
        sigismember(set,i)? putchar('1'):putchar('0');
    }
    putchar(10); 
    return;
}
//未决信号集合
int main(){
    //阻塞信号屏蔽字->信号屏蔽集合
    sigset_t newset,oldset,pset;
    //sigset_t 为初始化的
    sigemptyset(&newset);//这是我的集合初始化置为空
    //在集合中增加阻塞信号
    sigaddset(&newset,SIGINT);  
    sigaddset(&newset,SIGSEGV);  
    //sigint 终端中断符
    //add sigint 至集合中
    //就是在设置阻塞
    sigprocmask(SIG_BLOCK,&newset,&oldset);//阻塞值个集合中所有信号
    int n=20; //
    while(n>0){
      sigpending(&pset);//未决信号集
      print_sig(&pset); 
      sleep(1);
      n--;
    }
    //这里将oldset 还原了
    sigprocmask(SIG_SETMASK,&oldset,NULL);
    return 0;
}
