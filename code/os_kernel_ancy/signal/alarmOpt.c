#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>

int main(){
    alarm(5);
    sleep(3);
    unsigned int left=alarm(5);
    printf("left=%ud\n",left);
    while(1){
        printf(" sleep time");
        sleep(1);
    }
    printf("left=%ud\n",left);
    return 0;
}
