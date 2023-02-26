#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>


int main(){
    int fd=open("./hello.txt",O_RDONLY);
    printf(" fd %d : %s\n",0,ttyname(0));
    printf(" fd %d : %s\n",0,ttyname(1));
    printf(" fd %d : %s\n",0,ttyname(2));
    printf(" fd %d : %s\n",0,ttyname(fd));
    return 0;
}
