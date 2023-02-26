#include<vector>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include<stdio.h>
#include<sys/ioctl.h>
using namespace std;
int main(){
    //终端大小
    struct winsize size;
    if(!isatty(1))
    {
        printf(" 1  is to tty");
        exit(1);
    } 
    if(ioctl(1,TIOCGWINSZ,&size)<0){
        //读窗口的大小
        perror(" ioctl");
        exit(1);
    }
    printf("%d row ,%d columns\n",size.ws_row,size.ws_col);
    return 0;
}
