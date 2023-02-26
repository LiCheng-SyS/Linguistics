#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<errno.h>

int main(){
    //创建进程,输入自己的信息 ，父进程做父级进程，子进程做子进程的
    //成功则返回子进程的pid 会返回到父进程
    //对于父子进程都有这个变量
    char *msg;
    int n;
    pid_t chind_p_id= fork();
    //对于fork来说  线程就得同时出现了
    if(chind_p_id<0){
        perror("fork fail");
        exit(1);
    }
    if(chind_p_id==0){
        //子级
        //这里是打印父进程的id  
        n=6;
        while(n>0){
            printf("chind =pid %d and parent=%d\n",getpid(),getppid());
            //msg="chind Process~\n";
            sleep(1);
            n--;//循环输出
        }
    }else{
        //这里是自己的进程id 然而想得到子进程的id只能将fork的返回值记下来
        n=3;
        while(n>0)
        {
            printf("parten ->pid%d , parent 1->%d\n",getgid(),getppid());
            //父级 必然是>0
            //msg="parten Process~\n";
            sleep(1);
            n --;//循环输出三次

        }
    }
    //父级子级进程都会来这里
    /*  while(n>0){
        printf(msg);
        sleep(1);
        n--;
        }*/
    return 0;
}
