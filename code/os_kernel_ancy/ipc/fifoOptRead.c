#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>

int main(){  
    int fd= open("./tube",O_RDONLY);
    if(fd<0){
        perror("open fail");
        exit(1);
    }
    perror("open");
    char buf[20]; 
    ssize_t n=read(fd,buf,20); 
    write(1,buf,n);

    close(fd);
    return 0;
}
