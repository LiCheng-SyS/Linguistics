#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<time.h>


//declare initNode
typedef  struct Node{
    int data;
    struct  Node *lchind,  *rchind;
}Node; 

//declare root
typedef  struct Tree{
    Node *root;
    int length;
}Tree;

//initNode
Node *initNode(int val){
    Node *p=(Node *)malloc(sizeof(Node));
    p->data =val;
    p->lchind=p->rchind=NULL;
    return p;
}

Tree* InitTree(){   
    Tree *tree=(Tree *)malloc(sizeof(Tree));
    tree->root =NULL;
    tree->length=0;
    return tree;
}

Node* insert_node(Node* root,int val,int *flag){
    if(root==NULL){
       *flag =1;
       return  initNode(val);
    }
    //二叉排序
    if(root->data==val)return root;
    if(root->data> val) root->lchind =insert_node(root->lchind,val,flag);
    if(root->data < val) root->rchind=insert_node(root->rchind,val,flag);
    return root;
}

void insert(Tree* tree,int val){
    if(tree==NULL)return;
    int  flag=0;
    tree->root =insert_node(tree->root,val,&flag);
    tree->length+=flag;
    return;
}

void clear_node(Node *root){
    if(root==NULL)return;
    clear_node(root->lchind);
    clear_node(root->rchind);
    free(root);
    return ;
}


void clear_tree(Tree *tree){
    if(tree==NULL)return;
    clear_node(tree->root);
    free(tree);
    return;
}

void pre_order_node(Node *root){
    if(root==NULL)return;
    printf(" %d",root->data);
    pre_order_node(root->lchind);
    pre_order_node(root->rchind);
    return ;
}

//前序
void pre_order(Tree *tree){
    if(tree==NULL)return ;
    printf(" pre_order");
    pre_order_node(tree->root);
    printf("\n");
    return;
}

void mid_order_node(Node *root){
    if(root==NULL)return;
    mid_order_node(root->lchind);
    printf(" %d",root->data);
    mid_order_node(root->rchind);
    return ;
}

void mid_order(Tree *tree){
    if(tree==NULL)return ;
    printf(" mid_order");
    mid_order_node(tree->root); 
    printf("\n");
    return ;
}

void post_order_node(Node *root){
    if(root==NULL)return ;
    post_order_node(root->rchind);
    post_order_node(root->lchind);
    printf(" %d",root->data);
    return;
}

void post_order(Tree *tree){
    if(tree==NULL)return ;
    printf(" post_order");
    post_order_node(tree->root);
    printf("\n");
    return ;
}


void output_node(Node *root){
    if(root==NULL)return;
    printf("%d",root->data);
    if(root->rchind==NULL&& root->lchind==NULL)return;
    printf(" (");
    output_node(root->lchind);
    printf(", ");
    output_node(root->rchind);
    printf(" )" );
    return;
}


void output(Tree *tree){
    if(tree==NULL)return;
    printf("tree (%d)",tree->length);
    output_node(tree->root);
    printf("\n");
    return;
}


int main(){
    srand(time(0));
    Tree *tree=InitTree();
#define MAX_OP 10
    for(int i=0;i<MAX_OP;i++){
        int val =rand() % 100;
        insert(tree,val);
        output(tree);
    }
    pre_order(tree);
    mid_order(tree);
    post_order(tree);
    clear_tree(tree);
#undef MAX_OP
    return 0;
}
