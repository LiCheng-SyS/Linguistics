#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h> 



int main(){
    printf("%d\n",STDIN_FILENO);
    
    printf("%d\n",STDOUT_FILENO);
    
    printf("%d\n",STDERR_FILENO);
    
    return 0;
}
