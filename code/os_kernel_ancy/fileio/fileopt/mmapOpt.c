#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/mman.h>
#include<sys/types.h>
#include <sys/stat.h>

//建立内存映射
int main(){
    int fd=open("./hello.txt",O_RDWR);
    if(fd<0){
        perror("open file");
        exit(1);
    }
    char *p=(char *)mmap(NULL,10,PROT_WRITE,MAP_SHARED,fd,0);
    //((int *) (((char *)p)+1))[0]=0x30313233;
    // 可以直接看成字符数组
    p[0]='A';
    p[2]='B';
    p[3]='A';
    munmap(p,6);
    return 0;
}
