#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/wait.h>
void sig_child(int signo)
{
    int  sts;
    pid_t pid = wait(&sts);
    if(WIFEXITED(sts))
        printf("proc :pid=%d\n exit with code %d\n",pid,WEXITSTATUS(sts));
    else
        printf("lemon\n",WEXITSTATUS(sts));
    return;
}
int main(){
    pid_t pid=  fork();
    if(!~pid){
        perror(" frok fail");
        exit(1);
    }
    if(pid){
        //设置信号动作
        struct sigaction new_cat,old_act;  

        new_cat.sa_handler=sig_child;
        new_cat.sa_flags=0;    
        sigemptyset(&new_cat.sa_mask);
        //在父进程注册了子进程的处理动作
        sigaction(SIGCHLD,&new_cat,&old_act);    
      
        //SIG_IGN 子进程在终止时会自动清理，不会产生僵尸进程，也不会通知父进程
        //忽略子进程的进程
        if(old_act.sa_handler==SIG_IGN){
            printf("old handler is\n");
        }else{
            printf("old handler isn't ign\n");
        }

        int n=20;
        while(n--){
            printf(" wrok \n");
            sleep(2);
        }
    }else{
        //子进程终止时给父进程发SIGGHLD signal
        printf(" childern proccess pid%d\n",pid);
        sleep(3);
        exit(2);//终止时发送信号  
    }
    return 0;
}
