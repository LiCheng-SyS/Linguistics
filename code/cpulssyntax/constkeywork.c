#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>

int main(){

    char arr[10]={"heelo "};
    //这种为这段内存空间的访问是只读
    const char * p=arr;
    p[1]='1';
    //erro 只读变量不可赋值 
    return 0;
}
