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
    int fd=open("./tube",O_WRONLY);
    if(fd<0){
        perror("openw fail");
        exit(1);
    }
    
    write(fd,"hello FIFO\n",11);

    close(fd);
    return 0;
}
