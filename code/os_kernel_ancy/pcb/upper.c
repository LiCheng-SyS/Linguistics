#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <ctype.h>

int main(){
    int ch;
    while(~(ch=getchar())){
        putchar(toupper(ch));
    }
    return 0;
}
