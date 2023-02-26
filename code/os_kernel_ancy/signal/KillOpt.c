#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<error.h>
#include<signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid=fork();
    //  printf("pid=%d\n",pid);
    if(!~pid){
        printf("fork fail");
        exit(1);
    }
    if(pid){
        sleep(3);
        //SIGSEGV : 无效内存的引用
        //SIGPIPE : 无效管道
        //STGQUIT : 中断程序 产生core
        if(kill(pid,SIGQUIT)<0){
            perror("kill fail");
            exit(1);
        }
        int stats;
        //   返回导致子进程终止的信号的编号
        wait(&stats);
        if(WIFSIGNALED(stats)){
            //检查终止信号
            //返回导致子进程终止的信号的编号
            printf("children by signal %d\n",WTERMSIG(stats));
        }else{
            printf("child exit other\n");
        } 
    }else{
        //children
        while(1){
            printf("children process1 fail\n");
            sleep(1);
        }
    }
    return 0 ;
}
