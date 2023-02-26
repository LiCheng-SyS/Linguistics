#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


int main(){
    pid_t pid=fork();
    if(pid<0){
        perror("fork fail");
        exit(1);
    }
    if(!pid){
        //子
        int n =15;
        while(n>0){
            printf("chind process id %d\n",getpid());
            sleep(1);
            n--;
        }
        exit(1);
    }else{
        int stat_val;
        waitpid(pid,&stat_val,0);
        if(WIFEXITED(stat_val)) {
            //判断是否正常退出结束
            printf("Chind code %d\n",WEXITSTATUS(stat_val));//退出的状态码
        }else if(WIFSIGNALED(stat_val)){//信号终止调的
            printf("Chind abnormally ,signal%d\n",WTERMSIG(stat_val));//信号的状态码
        }
    }

    return 0;
}
