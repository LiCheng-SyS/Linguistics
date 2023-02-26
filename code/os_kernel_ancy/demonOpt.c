#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    //得到非leadr的进程 
    pid_t pid=  fork();
    if(!~pid){
        perror("fork fail");
        exit(1);
    }
    if(pid){
        exit(0);
    }

    //脱离会话
    pid_t  s_tid=setsid();
    printf(" new sessiobn id is %d\n",s_tid);
    if(chdir("/")<0){
        perror("chdir");
        exit(1);
    }
    close(0);
    //0最小的文件描述符

    open("/dev/null",O_RDWR);
    //往0上去写
    int  f_id = dup2(0,1);
    int  s_id = dup2(0,2);
    //全部重定向了 往里写往外读都是null -> null 
    //exec 去执行的输入输出 这时文件都没开不就报错了吗
    printf(" f1 %d\n",f_id);
    printf(" s1 %d\n",s_id);
    while(1) {
         sleep(1);
    }
    return 0;
}
