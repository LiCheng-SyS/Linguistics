#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<time.h>


//结构定义

typedef  struct Node{
  int data;
  //指针区域
  struct Node *next;
} Node;

typedef  struct List{
//  Node *head; //头指针
    Node head;// = NULL  虚拟节点  可以方便找到带插入的前一个位子
    int Length; //节点个数
} List; 

Node *getNewNode(int );
List  *init_list();
void clear_node(Node *);
void clear_list(List * );
int insert(List * ,int ,int );
int Remove(List * , int );

void hextoDec(int hex){
     int sum=0,mul=1;
      int i,r;
       int count=0;
       do{
             r=hex%16;
               for(i=0;i<count;i++)
                      mul*=16;
                 mul*=r;
                   sum+=mul;
                     mul=1;
                       count++; 
                        
       }while(hex/=16);
        printf("%d\n",sum);
          
 return ;       
}

//获取节点
Node *GetNode(int  val){
    Node * p =(Node *)malloc(sizeof(Node));
    //类似于 new 根据类型开辟空间
    p->data = val;
    p->next = NULL;
    return p;
}


List * init_list(){
     List *l=(List *) malloc(sizeof(List));
     l->head.next=NULL;//他是虚拟的所以给下一位  才是真实的地址空间
     l->Length=0;
     return l;
}

//回收 节点
void clear_node(Node * node){
  if(node ==NULL)return;
  free(node);
  return;
}


void clear_list(List * list){
  if(list==NULL)return ;
  //由于list 是往后结构是链状的 所以不能向上面的一样直接释放内存
  Node * p=list->head.next, *q; //当前链表的头节点地址
  while(p!=NULL){
     q=p->next; 
     clear_node(p);
     p=q; // 继续往下一只跑到最后一个为NULL为止
  }
  free(list);
  return ;
}


//结构操作


int insert(List * list,int index , int value){
    if(list==NULL)return 0 ;
    if(index<0 || index > list->Length)return 0; //位置不对 
     // 插入第一个节点时
    Node *p=&(list->head);//头节点
    Node *node=GetNode(value);//新插入节点的地址
    while(index-- ) p=p->next;   //带插入地址前一位
    node->next =p->next;//指向后一位的地址 实际为需要插入的地址
    p->next =node;//将前一位的地址  重新指向插入的哪一位
    list->Length += 1;
    return 1;
} 

int Remove(List * list,int index){
    if(list==NULL)return 0;
    if(index<0 || index >=list->Length) return 0;
    Node *p =&(list->head), *q; //q为中间交换变量
    while(index--) p=p->next; //记录待删除前一位的节点
    q=p->next; //  下位是删除的值 赋值 给中间地址
    p->next =q->next; //重新指向后一位
    clear_node(q);
    list->Length-=1;

    return 1;
}


void output(List *l){

    if(l==NULL)return;
    printf("list %d : " , l->Length );
    for(Node * p=l->head.next;p!=NULL ;p=p->next){
        printf("  p %d" , p->data);

    }
    printf("NULL\n");
    return ;
}

//头插法
void reverse(List *l){
  if(l==NULL)return;
 
  Node *p =l->head.next,*q;
  l->head.next=NULL;
  while(p!=NULL){
      q=p->next;
      p->next =l->head.next;
      printf("l->headnext -%p\n",l->head.next);
     // hextoDec(l->head.next);
      l->head.next=p;
      p=q;
  }
  return ;
}


int main(){

    srand(time(0));
    #define  MAX_OP 20
    List *l=init_list();

    for(int i=0;i<MAX_OP; i++){
        int op =rand() % 4;//4以内的数字
         printf(" op %d :",op);
        int val =rand() % 100; //100内的值
        int index =rand() % (l->Length +3)-1;

        switch(op){
             case 0 :
             case 1 :{
                         printf("insert %d  to %d to list =%d\n",val,index,insert(l,index,val)); 
                     }break;
             case 2 :{
                         printf("reverse  list \n"); 
                         reverse(l);
                     }break;
             case 3 :{
                         printf("remove item to %d from kist=%d\n",index,Remove(l,index));
                     }break;
                  }
                     output(l);
                    printf("\n");
    }
    #undef  MAX_OP
    clear_list(l);
 
    return 0;
}




