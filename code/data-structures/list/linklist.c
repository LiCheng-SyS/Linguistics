#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>



//结构定义

typedef  struct Node{
  int data;
  //指针区域
  struct Node *next;
} Node;

typedef  struct List{
//  Node *head; //头指针
    Node *head;// = NULL  虚拟节点  可以方便找到带插入的前一个位子
    int Length; //节点个数
} List; 



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
     l->head=NULL;
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
  Node * p=list->head, *q; //当前链表的头节点地址
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
   
}


int main(){

    

    return 0;
}
