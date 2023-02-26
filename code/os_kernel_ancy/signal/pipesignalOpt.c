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
    int pipefd[2];
    // 管道
    if(!~pipe(pipefd)){
        perror("pipe fail");
        exit(1);
    }

    pid_t  pid=   fork();
    if(!~pid){
        perror("pid fail\n");
        exit(1);
    }
    if(pid){
        close(pipefd[0]);
        close(pipefd[1]);
        printf("1\n");
        sleep(3);// 先把读端先关闭
        int sts;
        wait(&sts);
        printf("3\n");
        if(WIFSIGNALED(sts)){
            printf("signal=%d\n",WTERMSIG(sts));
        }else{
            printf("other ",WTERMSIG(sts));
        }
    }else{
        printf("2\n");
        sleep(3);//读端全部关闭了
        close(pipefd[0]);
        write(pipefd[1],"hello\n",6);
        sleep(10);
    }
    return 0;
}
