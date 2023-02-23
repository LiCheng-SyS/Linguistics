#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<time.h>



//每个空白序列回转空格
#define  COLOR(a,b) "\033["#b "m" a "\033[0m" 
#define  GREEN(a) COLOR(a,32)




typedef struct Stack{
    int *data;
    int top,size;
}Stack;

Stack *init(int  val){
    Stack *s=(Stack *)malloc(sizeof(Stack));
    s->data=(int *)malloc(sizeof(int) * val);
    s->size= val;
    s->top=-1;
    return s;
}


Stack *init(int);
int empty(Stack);
int expand(Stack);
void Clear(Stack);
int push(Stack,int);
int pop(int );
int top(Stack);
int output(Stack);

int empty(Stack *s){
    return s->top==-1;
}


int expand(Stack *s){
    //额外空间不为0就可以扩容
    int exr_size=s->size;
    int  *p;
    while(exr_size){
        p=(int *)realloc(s->data,(sizeof(int) *(s->size+exr_size)));
        if(p!=NULL)break; 
        exr_size /=2 ;                     
    }
    if(p==NULL)return 0;
    s->data=p;//重新拼接上申请的内存
    s->size+= exr_size; //空间同样更新
    return 1;
}

void clear(Stack *s){
    if(s== NULL) return;
    free(s->data); 
    free(s);
    return ; 
}


// 栈顶指针+1
int  push(Stack *s,int val){
    if(s==NULL)return 0;
    //头尾重合
    if(s->top ==s->size-1){
        if(!expand(s)) return 0;
        printf( GREEN(" suss expand  the size = %d\n"), s->size);
    }
    //s->top+=1; 顶部指针向后
    s->data[++s->top]=val;
    return 1;
}

int pop(Stack *s){
    if(s==NULL)return 0 ;
    if(empty(s))return 0;
    s->top-=1;//往左移动
    return 1;
}

int top(Stack *s)
{
    return  s->data[s->top];
}

void output(Stack *s){
    printf( " Stack :[" );
    for(int i =0; i<= s->top; i++){
        i  && printf(" ");
        printf( " %d ",s->data[i] );
    }
    printf("]\n " );
    return ;
}

int main(){
    srand(time(0));

#define  MAX_OP 20
    Stack *s=init(1);
    for(int i=0;i<MAX_OP;i++){
        int op = rand() % 4 ;
        int val =rand() % 100;
        switch(op){
        case 0:
        case 1:
        case 2:{
                   printf(" push %d to stack =%d\n",val,push(s,val));
               }break;
        case 3:{
                   if(empty(s)){
                       printf("fali to pop\n");

                   }else{
                       printf("succ to pop :%d\n",top(s));
                       pop(s);
                   }
               }break;
        }
        output(s),printf("\n");
    }
#undef MAX_OP

    return 0;
}
