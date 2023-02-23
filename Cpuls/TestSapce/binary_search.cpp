#include<vector>
#include<iostream>
#include<time.h>
#include<stdio.h>
#include <stdlib.h>
using namespace std;


typedef  struct Node{
    int key;
    struct Node *lchind, *rchind;

}Node;


Node *getNewNode(int key){
    Node *p=(Node *)malloc(sizeof(Node));
    p->key= key;
    p->lchind =p->rchind=NULL;

    return p;
}

Node *random_insert(Node  *root,int key){
    if(root == NULL) return getNewNode(key);
    if(rand() %2){
        root->lchind = random_insert(root ->lchind,key);
    }else{
        root->rchind =random_insert(root->rchind,key);
    }
    return root;
}

void pre_order(Node *root){
    if(root ==NULL)return;
    printf("kety %d\n",root->key);
    pre_order(root->lchind);
    pre_order(root->rchind);
    return ;
}


void in_order(Node *root){
    if(root ==NULL)return ;
    pre_order(root->lchind);
    printf("kety %d\n",root->key);
    pre_order(root->rchind);
    return ;
}



int main(int argc,char*  agrv[]){

    srand(time(0));
    if(argc !=2)return 0;
    int MAX_N=atoi(agrv[1]);//字符转int 
    Node *root =NULL;
    for(int i =1;i<MAX_N;i++){
        //构建多少个二叉树
        root=random_insert(root,i);
    }
    pre_order(root);printf("\n");
    in_order(root);printf("\n");
    // pre_order(root);printf("\n");

    return 0;
}
