#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <ctype.h>

int main(){
    FILE *fp = popen("./upper","w");
    if(!fp){
        perror("fp error");
        exit(1);
    }
    fprintf(fp ,"sucess  to go\n");
    pclose(fp);
    return 0;
}
