#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<time.h>

typedef  struct Queue{
    int *data;
    int length;
    int head,tail;
}Queue;

Queue *init(int n){
    Queue *p=(Queue *)malloc(sizeof(Queue));
    p->data=(int *) malloc(sizeof(int) * n );
    p->length =n;
    p->head =p->tail=0;
    return p;
}


void clear(Queue *q){
    if(q==NULL) return ;
    free(q->data);
    free(q);
    return;
}


//入队 push
int push(Queue *q,int val){
    if(q==NULL)return 0;
    if(q->tail==q->length)return 0;
    q->data[q->tail]=val;
    q->tail+=1;
    return 1;
}


bool empty(Queue *q){
    return q->head == q->tail;
}

//pop 出队

int pop(Queue *q){
    if(q==NULL)return 0;
    if(empty(q))return 0;
    q->head+=1;
    return 1;
}

//取头部元素
int front(Queue *q){
    return  q->data[q->head];
}

void output(Queue *q){
    printf("queue: [");
    for(int i=q->head;i<q->tail;i++){
        if(i!=q->head)  printf(" "); 
        printf("%d",q->data[i]);
    }
    printf(" ]");
    return ;
}

int QueueLen(Queue *q){
    return  q->tail-q->head;
}

int main(){
    srand(time(0));
#define MAX_OP 20
    Queue *q=init(MAX_OP);
    for(int i=0;i<MAX_OP;i++){
        int op=rand()%4;
        int val=rand()%100;
        switch(op){
        case 2:{
                   printf(" push  %d to Queue=%d\n",val,push(q,val));
               }break;
        case 3:{
                   if(empty(q)){
                       printf(" fait to pop a itrem \n");
                   }else{
                       printf("pop a iterm from Queu :%d\n",front(q));
                       pop(q);
                   }
               }break;
        case 1:{
                   printf(" QueueLen len -> : %d\n",QueueLen(q)); 
               }break;
        }
               output(q),printf("\n");   
    }
#undef MAX_OP
    clear(q);
    return 0;
}
