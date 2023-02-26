#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>

void *thr_fnl1(void *arg){
    printf("thread 1 returning %p\n",(char *)arg);
    return (void *)1;
}
void *thr_fnl2(void *arg){
    printf("thread 2 eixting->addr%p\n",(char *)arg);
    pthread_exit((void *) 2);
    return (void *)2;
}
void *thr_fnl3(void *arg){
    printf("thread 3 sleeping -> addr%p\n",(char *)arg);
    while(1){
        printf(" thread 3 sleeping\n");
        sleep(1);
    }
    return (void *)3;
}
int main(){
    pthread_t tid;
    void *ret;
    //第二参数为属性 ，第四个参数为函数指针回调参数
    pthread_create(&tid,NULL,thr_fnl1,NULL);
    pthread_join(tid,&ret); 

    pthread_create(&tid,NULL,thr_fnl2,NULL);
    pthread_join(tid,&ret); 

    pthread_create(&tid,NULL,thr_fnl3,NULL);
    sleep(2);
    pthread_cancel(tid);
    //取消当前线程请求
    pthread_join(tid,&ret);
    //等待线程终止,如果终止则立即返回
    
    printf(" thread 3 exit code %ld",(int64_t)ret);
    return 0;
}
