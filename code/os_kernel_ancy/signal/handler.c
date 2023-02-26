#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>

void opt_handler(int signo){
    printf(" get signo =%d\n",signo);
    return;
}
//信号操作
int main(){
    struct sigaction new_act,old_act;
    new_act.sa_handler=opt_handler;
    new_act.sa_flags=0;
   //初始化信号屏蔽集合
    sigemptyset(&new_act.sa_mask);
    //接受信号后将原始的的和新的各回都保存一份
    sigaction(SIGINT,&new_act,&old_act); //SIGINT 键盘中断
    int n=20;
    while(n>0){
        sleep(1);
        n--;
    }
    //20秒后会还原原始,和信号屏蔽字类似
     sigaction(SIGINT,&old_act,NULL);
    return 0;
}
