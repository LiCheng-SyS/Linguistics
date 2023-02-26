#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <errno.h>
#include <unistd.h>
int main(int argc,char **argv){
    write(5,"hello\n",6);
    //printf("O_NONBLOCK =%lu\n",O_NONBLOCK);
    putchar(10);
    // 16进制
    /*
       printf("flags =%#x\n",falgs);
       printf("O_RDONLY =%#x\n",O_RDONLY);
       printf("O_WRONLY =%#x\n",O_WRONLY);
       printf("O_RDWR =%#x\n",O_RDWR);
       printf("O_APPEND =%#x\n",O_APPEND);
       printf("O_NONBLOCK =%#x\n",O_NONBLOCK);
    //32770
    printf("O_ACCMODE =%#x\n",O_ACCMODE);

*/
    return 0;    
}
