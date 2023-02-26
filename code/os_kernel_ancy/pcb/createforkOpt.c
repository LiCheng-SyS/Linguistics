#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>


int add(int i ){
    return  i+1;
}

int main(){
   printf("res = %d",add(1));
    /*for(int i=0;i<10;i++){
        pid_t id1= fork();
        if(id1<0){
            perror("fork fail");
            exit(1);
        }
        if(!id1){
            printf("fokr %d let pid pid_t=%d, parten pid=%d\n",i,getgid(),getppid());
            sleep(2);
            //子进程要终止循环
            break;
        }
    }
    sleep(2);*/
    return 0;
}
