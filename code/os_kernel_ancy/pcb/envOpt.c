#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>


int main(){
    extern char **environ;
    /*    
          for(int i=0;environ[i];i++){
          printf("environ %s\n",environ[i]);
          }
          */
    printf("path val =[%s]\n",getenv("PATH"));
    setenv("PATH","Hell",1);
    printf("path val =[%s]\n",getenv("PATH"));
    return 0;
}
