#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>

#define SIZE 4

int main(void){
    int dates[SIZE];
    int *pri;
    
    double  bills[SIZE];
    double *prf;


    pri = dates ; 
    prf = bills ;

    printf("%23s %12s\n","int","double"); 
  
    for(int i=0 ; i < SIZE; i++){
        //%10p 16进制
        printf("pointers + %d: %10p %10p\n",i ,pri + i ,prf + i);
    }
    /*把数组地址复制给指针*/
    return 0;
}
