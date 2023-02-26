#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
#include <error.h>
#include <sys/wait.h>
int main(){
    int fd[2] ,n;
    pid_t pid;
    char buf[20];
    if(pipe(fd)<0){
        perror("pipe fail");
        exit(1);
    }
    pid=fork();
    if(pid<0){
        perror("fork fail");  
    }
    char grz[1024];
    if(pid>0){
       close(fd[0]);
       for(int i=0;i<100;i++){
         write(fd[1],grz,1024);
         printf("id i =%d\n",i);
       }
       // 把读端关闭
       //close(fd[1]);
       wait(NULL);//等待子进程结束
    }else{
        close(fd[1]);
        sleep(10);
      /* sleep(2);
      n=read(fd[0],buf,20);
      printf("n=%d\n",n);
      n=read(fd[0],buf,20);
      printf("n=%d\n",n);
      write(1,buf,n);
     */
      }
    return 0;
}
