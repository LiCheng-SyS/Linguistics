#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<time.h>
typedef  struct Goods{
    int data; //共享区
    struct Goods *next;
}Goods;

Goods *head=NULL;

//当前问题在于>>>>>> 头为空 ，一旦为空 释放 就是非法指针
//两个方法一旦一个内存做操作必须带锁


pthread_mutex_t headlock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t exist_goods=PTHREAD_COND_INITIALIZER;
void *producer(void *arg){
    Goods *nextg;
    while(1){
        nextg= (Goods*)malloc(sizeof(Goods));
        nextg->data=rand() %100;
        //生产者头插法
        //如果先到了 consumer()函数（）->数据什么都没有,他将锁丢出来。这里得到了锁
        pthread_mutex_lock(&headlock);
        nextg->next=head;
        head=nextg;
        pthread_mutex_unlock(&headlock);//这里会把锁又丢出去

        pthread_cond_signal(&exist_goods); //将信号发送给你 我这生产号了东西 消费者继续运,开始重新转起来
        printf("produce %d\n",nextg->data);
        sleep(rand()%3);
    }
}
//x消费 必须要先要先生产，如果没有生产好，则需要等待
void  *consumer(void *arg){
    Goods *k;
    while(1){
        pthread_mutex_lock(&headlock);
        if(!head){
            //等待条件发生,因为代码走到这里 其空间没有生产
            //等待extis 是否会触发信号。同时需要丢出去,不丢就会思索
           pthread_cond_wait(&exist_goods,&headlock);            
        }
        k=head;
        //已经释放了
        head=head->next;
        pthread_mutex_unlock(&headlock);
        printf("consume %d\n",k->data);
        free(k);
        sleep(rand()%3);
    }
}


int main(){
    //一条线程负责 生产， 一个线程在消费。
    srand(time(0));
    pthread_t pid,ctid;
    pthread_create(&pid,NULL,producer,NULL);
    pthread_create(&ctid,NULL,consumer,NULL);
   
    pthread_join(pid,NULL);
    pthread_join(ctid,NULL);
    return 0 ;
}
