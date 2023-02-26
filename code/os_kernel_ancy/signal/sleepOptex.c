#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>
//只要时钟唤醒了pos 以后 它首先就得执行指针中的动作捕捉内容
void sig_alarm_opt(int signo){
    return ;
}
//如果sleep 被提前唤醒,会将未休眠时间返回
unsigned int msleep(unsigned int sec){
    struct sigaction new_action ,old_action;
    sigset_t newmask,oldmask,sumask;
    //阻塞闹钟信号
    sigemptyset(&newmask);
    //设置新的信号
    sigaddset(&newmask,SIGALRM);
    //操作信号屏蔽字阻塞
    sigprocmask(SIG_BLOCK,&newmask,&oldmask);
    //替换ALARM的信号处理函数
   
    new_action.sa_handler=sig_alarm_opt;   
    new_action.sa_flags=0;
    sigemptyset(&new_action.sa_mask);
    sigaction(SIGALRM,&new_action,&old_action);//当前宏是时钟
   
    alarm(sec);//开启时钟
    sumask=oldmask;//读取原来的信号屏蔽字情况
    //删除对原来信号屏蔽字的情况
   sigdelset(&sumask,SIGALRM);
    //pause和挂起等待  | 临时设置信号屏蔽字为sumask ，并挂起程序
    sigsuspend(&sumask);//可能会在有些情况下 放开  
    //放开信号屏蔽字 oldmask 可能是没阻塞的,所以考虑用中间变量接受一下
    //未休眠的时间
    int  unslept=alarm(0);//信号以秒为单位传递给调用进程
    sigaction(SIGALRM,&old_action,NULL);
    sigprocmask(SIG_SETMASK,&oldmask,NULL);
    ///先恢复信号处理动作 ,next ->信号
    return unslept;
}
int main(){
    int n=10;
    while(n){
        printf("msleep 1s\n");
        msleep(1);
        n--;
    }
    return 0;
}
