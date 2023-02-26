#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc ,char *argv[]){
    //返回的缓冲区的结构体指针  参数1路径，参数2模式
    //带缓冲的操作
    if(argc < 2) {
        printf(" cmd :filename\n");
        return 1;
    }
    FILE  *fp=fopen("./hello.txt","r+");
    //非0
    if(!fp){
        perror(" open fail");
        return 1;
    }
    //fgetc每次都会往下移动i
    fputc('1',fp);
    fputc('2',fp);
    fputc('C',fp);
    //首先需要移动到最开始,向前或者向后偏移 + 向前   -向后
    //lseek(fp,!EOF,SEEK_END);   
    fseek(fp,!EOF,SEEK_END);//如果偏移会覆盖
    printf("size =%d\n",ftell(fp)); 
    putchar(10);    
    fclose(fp);
    return 0;
}
