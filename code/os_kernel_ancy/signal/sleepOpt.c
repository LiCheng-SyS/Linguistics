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
    new_action.sa_handler=sig_alarm_opt;   
    new_action.sa_flags=0;
    sigemptyset(&new_action.sa_mask);
    sigaction(SIGALRM,&new_action,&old_action);//当前宏是时钟
    

    alarm(sec);//休息sec
    //挂起等待信号抵达
    int res= pause();
    printf("res = %d\n",res);
    //未休眠的时间
    int  unslept=alarm(0);
    sigaction(SIGALRM,&old_action,NULL);
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

