#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#include<stdlib.h> 
#include<stdio.h> 
#include<string.h>
using namespace std;

#define  BASE  26
typedef struct Node {
    int falg ;
    struct Node *next[BASE], *fail;
}Node;  
typedef struct Queue{
    Node **data;
    int head, tail;
}Queue;
  
Queue *initque(int len){
    Queue *q=(Queue *) malloc(sizeof(Queue));
    q->data = (Node **)malloc(sizeof(Node) * len);
    q->head = q->tail =0;
    return q;
}
void clearqueue(Queue *q){
    if(q==NULL) return; 
    free(q->data);
    free(q);
    return ;
}

void push(Queue *q, Node *node){
    q->data[q->tail++] = node; 
    return ;
}

int  empty(Queue *q){
    return q->tail - q->head ==0; 
}
void pop(Queue *q){
    if(empty(q)) return ;
    q->head +=1;
}
Node *front(Queue *q){
    return q->data[q->head];
}
int node_cnt = 0 ;
Node *getnewNode(){
    node_cnt += 1 ;
    Node *p= (Node *)malloc(sizeof(Node));
    p->falg = 0 ;
    p->fail= NULL;
    for(int i = 0; i < BASE; i++){
        memset(p->next , 0 ,sizeof(Node *) * BASE);
        //p->next[i] = NULL;
    }
    return p;
}

inline int ind(char ch){
    return  ch -'a';
}

void insert(Node *root ,const char *str){
    Node *p = root;
    //遍历字符串的每一位
    for(int i = 0; str[i];i++){
        if(p->next[ind(str[i])]==NULL) {
            p->next[ind(str[i])] =getnewNode();
        }
        p = p->next[ind(str[i])];
        p->falg =1;
    }
}
void clear(Node  *root){
    if(root == NULL) return; 
    for(int i = 0; i < BASE; i++){
        clear(root->next[i]);
    }
    free(root);
}

//当前子节点 应判断子节点x 应该指向父节点 fail 指针下面的子节点是否相等 直接判断 这各x == y。
//fail 首先是1 :根结点第一层的的fail 指针应该属于挂根节点本身的.
// 第二层往后 根据其父节点的fail指针的指向，确定当前fail指针的指向
void build_fail(Node *root){
    //需要分层建立，如果要建立队列，则需要总结点数量：
    Queue *q =initque(node_cnt);
    for(int i =0 ;i < BASE; i++){
        if(root->next[i] ==NULL) continue; 
        root->fail = root;
        push(q, root->next[i]);
    }
    while(!empty(q)){
        Node *p=front(q);

        for(int i = 0; i< BASE; i++){
            Node *k=p->fail; 

            
        }

        pop(q);
    }
    clearqueue(q);
}

int main(){
    
    int n ;
    char s[100];
    cin >> n ;
    Node *root =getnewNode();
    for(int i = 0 ; i < n; i++){
        cin >> s; 
        insert(root, s);
    }
    // 以上为init 字典树完成        
    build_fail(root);
    return   0;
}
