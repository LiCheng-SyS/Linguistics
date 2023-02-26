#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<time.h>


#define  COLOR(a,b)"\033[" #b "m" a "\033[0m"
#define  GREEN(a) COLOR(a,32)


#define  RCOLOR(a,b)"\017[" #b "m" a "\017[0m"
#define  RED(a) RCOLOR(a,16)


typedef  struct Queue{
    int *data;
    int length;
    int head,tail;
    int cnt;
}Queue;

Queue *init(int n){
    Queue *p=(Queue *)malloc(sizeof(Queue));
    p->data=(int *) malloc(sizeof(int) * n );
    p->length =n;
    p->head =p->tail=0;
    p->cnt=0;
    return p;
}


void clear(Queue *q){
    if(q==NULL) return ;
    free(q->data);
    free(q);
    return;
}

int  expand(Queue *q){
    int extr_size=q->length;
    int *p;
    while(extr_size)
    {
        p=(int*)malloc(sizeof(int)*(q->length+extr_size));
        printf(RED("update front %d\n"),sizeof(p));
        if(p!=NULL)break;

        extr_size >>= 1;
    } 

    if(p==NULL)return 0;
    for(int i =q->head,j=0;j<q->cnt;j++){
        p[j]=q->data[(i+j) % q->length];
    }   
    free(q->data);
    q->data=p;
    q->head=0,q->tail=q->cnt;
    q->length += extr_size;
    return 1;
}



//入队 push
int push(Queue *q,int val){
    if(q==NULL)return 0;
    if(q->cnt==q->length){
        if(!expand(q))return 0;
        printf(GREEN( "sucess tp exand  the size = %d\n "),q->length);
        expand(q);
    }

    q->data[q->tail]=val;
    q->tail+=1;
    if(q->tail ==q->length) q->tail =0; // 直接拿到前面来
    q->cnt+=1; 
    return 1;
}


bool empty(Queue *q){
    return q->cnt=0;
}

//pop 出队

int pop(Queue *q){
    if(q==NULL)return 0;
    if(empty(q))return 0;
    q->head+=1;
    if(q->head==q->length)  q->head=0;
    q->cnt-=1;
    return 1;
}

//取头部元素
int front(Queue *q){
    return  q->data[q->head];
}

void output(Queue *q){
    printf("queue: [");
    for(int i=q->head,j=0;j< q->cnt;j++){
        //  if(j)  printf(" ");
        j && printf(" ");
        printf("%d",q->data[ (i+j)] % q->length);
    }
    printf(" ]");
    return ;
}

int QueueLen(Queue *q){
    return  q-> cnt;
}

int main(){
    srand(time(0));
#define MAX_OP 20
    Queue *q=init(1);
    for(int i=0;i<MAX_OP;i++){
        int op=rand()%4;
        int val=rand()%100;
        switch(op)
        {
        case 0:{}
        case 1:{}
        case 2:{
                   printf("quque len %d",QueueLen(q));
                   printf(" push  %d to Queue=  %d\n",val,push(q,val));
               }break;
        case 3:{
                   if(empty(q)){
                       printf(" fait to pop a itrem \n");
                   }else{
                       printf("pop a iterm from Queu : %d\n",front(q));
                       pop(q);
                   }
               }break;
               // case 1:{
               //          printf(" QueueLen len -> : %d\n",QueueLen(q)); 
               //    }break;
        }
        output(q),printf("\n");   
    }
#undef MAX_OP
    clear(q);
    return 0;
}
