#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>


typedef struct Node{
    char data;
    struct Node *lchind, *rchind;
}Node;


typedef  struct Tree{
    Node *root;
    int length;
}Tree;

typedef struct  Stack{
    Node **data; //node *data 只是有连续的存储空间 存储的是node 只是节点 ， **是每个存储的内容的地址
    int top, size;
}Stack;


Node *getNewNode(char val){
    Node *p=(Node *) malloc(sizeof(Node));    
    p->data=val;
    p->lchind=p->rchind=NULL;
    return p;
}

Tree *getNewTree(){
    Tree *tree=(Tree *)malloc(sizeof(Tree));
    tree->root=NULL;
    tree->length=0;
    return tree;
}

Stack *initStack(int n){
    Stack *s1=(Stack *)malloc(sizeof(Stack));
    s1->data=(Node **)malloc(sizeof(Node) * n);
    s1->top=-1;
    s1->size=n;
    return  s1;
}

// 返回 栈顶元素
Node *top(Stack *s){
    return s->data[s->top];
}

int empty(Stack *s){
    return s->top==-1;
}

int push(Stack *s,Node *val){
    if(s==NULL) return 0;
    if(s->top ==s->size -1 ) return 0;
    s->top+=1;
    s->data[s->top]=val;
    return 1;
}


int pop(Stack *s){
    if(s==NULL)return 0; 
    if(empty(s)) return 0;
    s->top-=1;
    return 1;
}

void clear_stack(Stack *s1){
    if(s1==NULL) return;
    free(s1->data);
    free(s1);
    return ;
}

void clear_node(Node *root){
    if(root==NULL) return;
    free(root->lchind);
    free(root->rchind);
    free(root);
    return;
}

void clear_tree(Tree * tree){
    if(tree==NULL)return;
    clear_node(tree->root);
    free(tree);
    return;
}

Node *buildertable(const char *str,int *node_numer){
    Stack *s=initStack(strlen(str));
    int flag=0;
    //确定关系
    Node *temp=NULL,*p=NULL;
    while(str[0]){
        switch(str[0])
        {
        case '(':{
                     push(s,temp);
                     flag=0;
                 }break;
        case ')':{
                     p=top(s);//记录一下栈顶元素
                     pop(s);
                     flag=0;
                 }break;
        case ',':flag=1;break;//当前点只要遇到就要挂左节点了
        case ' ':flag=1;break;//空格不做处理
        default:
                 temp= getNewNode(str[0]);
                 if(!empty(s)&&flag==0){   //flage = 0 则没有遇到,逗号 所以挂左子树
                     top(s)->lchind=temp;
                 }else if(!empty(s)&& flag==1){
                     top(s)->rchind=temp;  // 遇到了=1 则遇到了,逗号，所以挂右子树
                 }
                 ++(*node_numer);//长度
                 break;
        }
        str++;
    }
    clear_stack(s);
    if(temp && p==NULL)p=temp;
    return p;
}




void pre_order_Node(Node *node){
    if(node==NULL) return ;
    printf("%c ",node->data);
    pre_order_Node(node->lchind);
    pre_order_Node(node->rchind);
    return ;
}

void pre_order(Tree *tree){
    if(tree==NULL)return;
    printf("pre_order (%d) :",tree->length);
    pre_order_Node(tree->root);
    printf("\n");
    return ;
}



void in_order_Node(Node *node){
    if(node==NULL) return ;
    in_order_Node(node->lchind);
    printf("%c ",node->data);
    in_order_Node(node->rchind);
    return ;
}

void in_order(Tree *tree){
    if(tree==NULL)return;
    printf("in_order (%d) :",tree->length);
    in_order_Node(tree->root);
    printf("\n");
    return ;
}


void post_order_Node(Node *node){
    if(node==NULL) return ;
    post_order_Node(node->lchind);
    post_order_Node(node->rchind);
    printf("%c ",node->data);
    return ;
}

void post_order(Tree *tree){
    if(tree==NULL)return;
    printf("on_order (%d) :",tree->length);
    post_order_Node(tree->root);
    printf("\n");
    return ;
}



int main(){
    char str[1000]={0};
    int node_numer=0;
    scanf("%[^\n]s",str);
    getchar();
    Tree * tree=getNewTree();
    tree->root=  buildertable(str,&node_numer);
    tree->length=node_numer;
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clear_tree(tree);
    return 0;
}
