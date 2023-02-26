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

void *producer(void *arg){

    Goods *nextg;
    while(1){
        nextg= (Goods*)malloc(sizeof(Goods));
        nextg->data=rand() %100;
        //生产者头插法
        nextg->next=head;
        head=nextg;
        printf("produce %d\n",nextg->data);
        sleep(rand()%3);
    }
}
//x消费
void  *consumer(void *arg){
    Goods *k;
    while(1){
        k=head;
        //已经释放了
        head=head->next;
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
