#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>

#define  NUM 15
//局部就是0
int q[NUM];
int head,tail;
sem_t blank_number,goods_number;

void *producer(void *arg){
    while(1){
        //生产的条件是需要有往后
        sem_wait(&blank_number);
        q[tail]=rand()%100+1;
        printf("producer %d\n",q[tail]);
        tail=(tail+1) % NUM; //操作+1
        //这里注意顺序
        sem_post(&goods_number);//这里要add商品,让他释放出去
        sleep(rand()%3);//很可能溢出
    }
}

//生产则需要竞争都是空位，消费者需要竞争都是产品
void *consumer(void *arg){
    while(1){
        sem_wait(&goods_number);//等待到商品
        printf(" q[head]%d\n",head); 
        printf("consumer %d\n",q[head]);
        q[head]=0;
        head=(head+1) % NUM;
        sem_post(&blank_number);
        sleep(rand()%3);
    }
}

int main(){
    srand(time(0));
    sem_init(&blank_number,0,NUM);
    sem_init(&goods_number,0,0);//商品应该都是0
    pthread_t pid,cid,cid1,cid2;
    pthread_create(&pid,NULL,producer,NULL);
    pthread_create(&cid,NULL,consumer,NULL);
    pthread_create(&cid1,NULL,consumer,NULL);
    pthread_create(&cid2,NULL,consumer,NULL);
    pthread_join(pid,NULL);
    pthread_join(cid,NULL);
    pthread_join(cid1,NULL);
    pthread_join(cid2,NULL);
    return 0;
}

