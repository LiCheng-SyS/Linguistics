#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <error.h>
#include <strings.h>
#include <sys/wait.h>
int main(){
    //创建key值  标记，传入的文件号和val值是均衡的
    key_t key=ftok("./popenOptread.c",9);
    if(key<0){
        perror("  ftok fail");
        exit(1);
    }
    //printf("key =0%x\n",key);
    //只会给一页的整数位 ，用的时候别越界就行
    int sid=shmget(key,20,IPC_CREAT |0666);//申请内存
    if(sid<0){
        perror("shmget  fial");
        exit(1);
    }
    //shmget 已经在内核中创建好了共享内存
    char * shmadd;
    shmadd=(char *)(shmat(sid,NULL,0));

    if(*(int *)shmadd<0)
    {
        perror("shmat");
        exit(1);
    }
    snprintf(shmadd,20,"hello\n");
    printf(" shmp=%s\n",shmadd);
    pid_t pid=   fork();
    if(pid){
        //读取用户输入
        while(1){
            scanf("%s",shmadd);//应该先放缓冲区的
            //阻塞读
            if(!strcmp(shmadd,"quit")){
                //相同的话 退出
                break;
            }
        }
        wait(NULL);//等待子
    }
    else{
        while(1){
            if(!strcmp(shmadd,"quit")){
                break;
            }
            //非空打印
            if(*shmadd){
               printf("%s\n",shmadd);
               bzero(shmadd,20);
            }
            sleep(1);
        }    
    }
    shmdt(shmadd);
    //取消映射关系
    return 0;
}
