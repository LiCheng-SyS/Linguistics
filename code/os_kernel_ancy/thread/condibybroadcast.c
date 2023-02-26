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
        pthread_cond_broadcast(&exist_goods); //将信号广播 消费者这里这回生产出，将锁在次丢出去,只生产了一条数据
        printf("produce %d\n",nextg->data);
        sleep(rand()%3);
    }
}
//x消费 必须要先要先生产，如果没有生产好，则需要等待
void  *consumer(void *arg){
    Goods *k;
    while(1){
        pthread_mutex_lock(&headlock);
       // 一直等 有条件满足为止
        while(!head){
            //等待条件发生,因为代码走到这里 其空间没有生产
            //等待extis 是否会触发信号。同时需要丢出去,不丢就会思索
            //四个线程都在等,不管那个线程得到了锁都会丢出去。
            //四个线程都等着在，如果有一个线程拿到了，如果第二个线程来拿的时候就直接非法指针
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
    pthread_t pid,ctid,ctid1,ctid2,ctid3;
    pthread_create(&pid,NULL,producer,NULL);
    pthread_create(&ctid,NULL,consumer,NULL);
    pthread_create(&ctid1,NULL,consumer,NULL);
    pthread_create(&ctid2,NULL,consumer,NULL);
    pthread_create(&ctid3,NULL,consumer,NULL);
    pthread_join(pid,NULL);
    pthread_join(ctid,NULL);
    pthread_join(ctid1,NULL);
    pthread_join(ctid2,NULL);
    pthread_join(ctid3,NULL);
    return 0 ;
}
