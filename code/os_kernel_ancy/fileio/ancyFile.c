#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>


int main(){
    //标准输出文件
    for(int i =0;i<1025;i++){
        fputc('A',stdout); 
    }
    fputc('A',stdout); 
    fputc('B',stdout); 


    while(1){

    }

    return 0;
}
