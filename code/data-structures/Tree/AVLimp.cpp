// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <stack>
// #include <queue>
// #include <map>
// #include <algorithm>
// #include <set>

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// using namespace std;
#define max(a, b)((a) > (b) ? (a) : (b))
typedef struct Node{
    int key, height;
    struct Node *lchind, *rchind;
}Node;

Node __NIT; // 其目的计算树高  | vir 节点来处理AVL 的空节点，
#define NIL (&__NIT)
__attribute__((constructor))
//然后在程序启动时，通过 __attribute__((construct))
// 宏定义来调用 init_NIL 函数，将 NIL 初始化为空节点。
void init_NIL(){
    NIL->key = 0;
    NIL->lchind = NIL->rchind = NIL; //左右指针全部挂空
    NIL->height = 0;
    return ;
}

void Update_height(Node *root){
     if (root == nullptr) {
        return;
    }
    root->height=max(root->lchind->height,root->rchind->height) + 1;
    return;
}

Node *getNewNode(int key){ 
    Node *p = (Node *)malloc(sizeof(Node));
    p->key=key;
    p->lchind = p->rchind = NIL; //T同样全部vim
    p->height = 1;
    return p; 
}

Node *insert_Node(Node *root, int key){
    if(root == NIL) return getNewNode(key);
    if(root->key ==key) return root;
    if(key  < root->key) {
        root->lchind =insert_Node(root->lchind,key);     
    }else{
        root->rchind =insert_Node(root->rchind,key);
    }
     Update_height(root);
     return root; 
}

Node *pred(Node *root){
    Node *temp=root->lchind;
    while(temp->rchind !=NIL) temp=temp->rchind;
    return temp;
} 

//根据AVL树的定义，左子树中所有节点的键值应该小于父节点的键值，右子树中所有节点的键值应该大于父节点的键值。
Node * erase_Nood(Node *root,int key){
    if(root == NIL) return root;
    if(key < root->key ) {
        root->lchind =erase_Nood(root->lchind,key);
    }else if(key > root->key){
        root->rchind = erase_Nood(root->rchind, key);
    }else{
         if (root->lchind == NIL || root->rchind ==NIL){
             //删除不为0 或不为1的节点的
            Node *temp = (root->lchind == NIL ? root->rchind : root->lchind);
            free(root);
            return temp;
         } else{
            //度为2的节点 ->>>> 找到前驱
            Node *per= pred(root);
            //前驱节点覆盖到当前根结点
            root->key = per->key; 
            root->lchind= erase_Nood(root->lchind,per->key);
         }
    }
    //更新树高
    Update_height(root);
    return root ;
}

// 释放
void clear(Node *root)
{
    if (root == NULL)
        return;
    clear(root->lchind);
    clear(root->rchind);
    free(root);
    return;
}

int main()
{

    return 0;
}

