#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<errno.h>

int main(){
    pid_t pid=fork();
    if(pid<0){
        perror("fork fial");
        exit(1);
    }
    if(pid){
        //非0 父线程 不会去回收 已经死的子线程
        while(1)
            sleep(1);
    }else{
        exit(1);
    }
    return 0;
}
