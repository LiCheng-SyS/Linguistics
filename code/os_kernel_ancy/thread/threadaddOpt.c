#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>

int count=0;
void *cntadd(void *arg){
    int val;
    for(int i=0;i<5000;i++){
        val=count;
        printf("%p: %d\n",pthread_self(),val);
        count=val+1;
    }
    return NULL;
}


int main(){
    //线程id
    pthread_t tida,tidb;
    pthread_create(&tida,NULL,cntadd,NULL);
    pthread_create(&tidb,NULL,cntadd,NULL);
    pthread_join(tida,NULL);
    pthread_join(tidb,NULL);
    return 0;
}
