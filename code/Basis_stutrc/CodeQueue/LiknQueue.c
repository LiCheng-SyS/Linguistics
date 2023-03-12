#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<time.h>


typedef struct  LinkList{
    int  data;
    struct LinkList * next;
}Node;

typedef struct Queue{
    Node  vimhead; 
    Node *tail;
    int len,cnt;
}Queue;



//待入队的整形val 
Node *InitNode(int val){
    Node *p =  (Node *)malloc(sizeof(Node));
    p->data=val;
    p->next=NULL;
    return p;
}

Queue *initLinkQueue(){
    Queue *q=(Queue *)malloc(sizeof(Queue));
    q->vimhead.next=NULL;
    q->tail=&(q->vimhead);
    q->len =0;
    return q;
}

void clear_Node(Node *node){
    if(node== NULL) return;
    free(node);
    return;
}


void ClearQueue(Queue *q){
    if(q==NULL)return ;
    Node *p=q->vimhead.next,*temp;//指向真的 首地址
    while(p){
        temp=p->next;
        clear_Node(p);
        p=temp;
    }
    free(q);
}

int empty(Queue *q){
    return q->len==0;
}


int front(Queue *q){
    return q->vimhead.next->data;
}

int push(Queue *q ,int val){
    if(q==NULL)return 0;
    Node *node=InitNode(val);//直接从队尾插入 
    q->tail->next=node; 
    // tail- > next 挂空了？   
    q->tail =node;// 新插入的节点当尾节点
    q->len +=1;
    return 1;
}


int pop(Queue *q){
    if(q==NULL) return 0;
    if(empty(q)) return 0;
    Node *temp =q->vimhead.next;
    q->vimhead.next=temp->next;
    clear_Node(temp);
    q->len -=1;
    if(q->len==0)  q->tail= &(q->vimhead);  
    return 1;
}



void output(Queue *q){
    printf("Queue (%d) :[",q->len);
    for(Node *p=q->vimhead.next;p!=NULL; p=p->next){
        p !=q->vimhead.next && printf(" ");
        printf("%d",p->data);
    }
    printf("]\n");
    return ;
}

int main(){
    srand(time(0));
#define MAX_OP 20
    Queue *q=initLinkQueue();

    for(int i=0; i < MAX_OP;i++){
        int val =rand() % 100;
        int op = rand() % 4; 
        switch(op){
        case 0:
        case 1:
        case 2:{
                   printf("push %d to Queue = %d\n",val,push(q,val));
                   output(q),printf("\n");
               }break;
       case 3:{
                   if(empty(q)){
                       printf(" fali pop form queue");
                   }else{
                       printf("pop to  popL:%d\n",front(q));
                       pop(q);
                       output(q), printf("\n");               
                   }
               }break;
        }
        printf("push %d to Queue=%d\n",val,push(q,val));
        output(q),printf("\n");
    
    }
     system("pause");
#undef  MAX_OP
    ClearQueue(q);
    return 0;
}
