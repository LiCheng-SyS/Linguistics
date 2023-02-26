#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>

int main(){
    
    //本质上调都是exevn(2);
    //第一个是路径名，中间是不变参 ,最后一个是哨兵
    execlp("/usr/bin/ls","ls","-l",NULL);
   
    return 0;
}
