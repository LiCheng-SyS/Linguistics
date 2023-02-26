#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<time.h>


#define swap(a,b){\
   __typeof(a) __temp=a;\
    a=b;b=__temp;\
}


typedef  struct proiority_quque{
    int *data;
    int cnt,size;
}proiority_quque;

proiority_quque * initqueue(int n){
    proiority_quque *q=(proiority_quque *)malloc(sizeof(proiority_quque));
    q->data=(int *)malloc(sizeof(int) *n+1);
    q->cnt=0;
    q->size=n;
    return q;
}

void clearqueue(proiority_quque *q){
    if(q==NULL)return ;
    free(q->data);
    free(q);
    return;
}

int empty(proiority_quque *q){
    return q->cnt ==0;
}

int top(proiority_quque *q){
    return q->data[1];
}

//大顶堆
int push(proiority_quque *q,int val){
    if(q==NULL)return 0;
    if(q->cnt==q->size)return 0;
    q->data[++q->cnt]=val;
    //自下向上
    int ind=q->cnt;
    while(ind>>1 && q->data[ind] > q->data[ind >> 1]){
        swap(q->data[ind],q->data[ind >> 1]);
        ind >>=1;
    }
    return 1;
}

int pop(proiority_quque *q){
    if(q==NULL)return 0;
    if(empty(q))return 0;
    q->data[1]=q->data[q->cnt--];
    //向下调整
    int ind=1;
    while((ind << 1) <=q->cnt){
        int temp=ind ,l=ind << 1,r=ind <<1 | 1;//偶数或1等与+1
        if(q->data[l]>q->data[temp])temp=l;
        if(r <=q->cnt && q->data[r]> q->data[temp])temp=r;
        if(temp==ind) break;
        swap(q->data[temp],q->data[ind]);
        ind =temp;
    }
    return 1;
}


int main(){
    srand(time(0));
#define  MAX_OP 20
    proiority_quque *q=initqueue(MAX_OP);
    for(int i=0;i<MAX_OP;i++){
        int val =rand()%100;
        push(q,val);
        printf(" insert %d to the proiority_quque\n",val);
    }
    for(int i=0;i<MAX_OP;i++){
        printf("%d ",top(q));
        pop(q);
    }
    printf("\n");
#undef  MAX_OP
    clearqueue(q);
    return 0;
}
