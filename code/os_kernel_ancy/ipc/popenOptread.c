#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<error.h>
#include <ctype.h>

int main(){
    FILE *fp= popen("cat ./1.txt","r");

    if(!fp){
        perror("popen");
        exit(1);
    }

    //作为流的管到用fp 去接   getc 的返回为c
   // getc
    int c;
           
    while(~(c=getc(fp))){
        putchar(toupper(c));   
    }
    return 0;
}
