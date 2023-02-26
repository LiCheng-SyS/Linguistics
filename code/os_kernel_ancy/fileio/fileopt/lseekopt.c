#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<sys/types.h>
#include <sys/types.h>
#include <unistd.h> 

int main(int argc,char *argv[]){
    //if(argc <2){
       // printf("user cmd filename\n");
      //  return -1;
    //}
    //printf("%s\n",argv[1]);
    int fd;
    if((fd=open("./hello.txt",O_RDONLY))<0){
        perror("OPEN FAIL");
        exit(1);
    }  //拿宏替换8进制也是可以的
    char c;
    read(fd,&c,1);
    write(STDOUT_FILENO,&c,1);

    int pos=lseek(fd,5,SEEK_CUR);
    read(fd,&c,1);
    write(STDOUT_FILENO,&c,1);
    printf(" pos %d\n",pos);
    close(fd);;
    return 0;
}


