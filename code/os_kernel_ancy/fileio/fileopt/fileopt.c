#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>

int main(int argc,char *argv[]){
    FILE *fp=fopen("./hello.txt","r+");
    int a=3;
    fprintf(fp," d=%d",a);
    fclose(fp);
    return 0;
}
