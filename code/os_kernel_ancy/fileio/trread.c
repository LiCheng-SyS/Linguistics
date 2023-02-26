#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
int main(int argc,char *argv[]){
    char buf[20];
    int  n,i;
    //文件描述符 ,自动打开文件描述符
    while(1){

    n =read(STDIN_FILENO,buf,10);
    if(!n){
        perror("READ STDIN_FILENO" );
        exit(1);
    }

    if(n==0)break;
    printf(" read %d bytes\n",n);
//标准输入
    write(STDOUT_FILENO,buf,1);
    write(STDOUT_FILENO,"\n",1);
    printf("\n");
    }
    return 0;
}
