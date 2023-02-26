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

void init_NIL();
void Update_height(Node *root);
Node *getNewNode(int key);
Node *insert_Node(Node *root, int key);
Node *pred(Node *root);
Node *erase_Nood(Node *root,int key);
void clear(Node *root);
Node *maintain(Node *root);    

Node __NIT; // 其目的计算树高  | vir 节点来处理AVL 的空节点，
#define NIL (&__NIT)
__attribute__((constructor))
    //然后在程序启动时，通过 __attribute__((construct))
    // 宏定义来调用 init_NIL 函数，将 NIL 初始化为空节点。
    void init_NIL(){
        NIL->key = -1;
        NIL->lchind = NIL->rchind = NIL; //左右指针全部挂空
        NIL->height = 0;
        return ;
    }

void Update_height(Node *root){
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


//左旋 。---定义临时变量指向旋转后的根节点 
//由于是子树的右节点失衡
//首先将右作节点拉上去做root 
//右子树变成 新的子树的根 ，并将原来root 节点作为新的子树的左子树
//将节点全部拉过去左边
Node *left_rotate(Node *root){
    printf("left_rotate %d\n",root->key);
    Node *temp =root->rchind;  
    //往左拉,翻转的根节点
    root->rchind =temp->lchind;
    //是将 temp 的左子树挂在了 root 的右子树的位置
    temp->lchind = root;
    //将原来的根节点作为新的子树的左子树
    
    Update_height(root);
    Update_height(temp);
    return temp;
}

//对称
Node *rigth_rotate(Node *root){
    printf("rigth_rotate %d\n",root->key);
    Node *temp= root->lchind;
    root->lchind = temp->rchind;
    temp->rchind =root ;
    Update_height(root);
    Update_height(temp);
    return temp;
}
const char *maintain_str[]={" ","LL","LR","RL","RR"};

Node *maintain(Node *root){
    if(abs(root->lchind->height - root->rchind->height) <=1) return root ;
    //需要调整了
    
    int  main_type= 1;
    //l 类型的失衡了
    if(root->lchind->height > root->rchind->height ){
        //向左调整 lr类型的调整
        if(root->lchind->rchind->height > root->lchind->lchind->height ){
            //如果子树的右值> 子树的左值  向左调整
            root->lchind= left_rotate(root->lchind);
            printf("lerf_rotate %d\n", root->lchind->key );
            main_type = 2; 
            // lR
        }else{
            // LL
            main_type =1;
        }
        //小的左旋完成需要拉着根节点进行大的右旋
        
        printf("rigth_rotate %d\n",root->rchind->key);
        root =rigth_rotate(root);
       //可能会破坏子树的平衡性，使得子树的平衡因子不再为 {-1, 0, 1}
       //因此，如果在左旋操作后，子树的平衡因子变成了 -2
       //就需要进行右旋操作来重新平衡子树。
    }else{ 
           if(root->lchind->rchind->height < root->lchind->lchind->height){
              root->rchind =rigth_rotate(root->rchind);
              printf("rigth_rotate %d\n",root->rchind->key);
              // RL 
              main_type = 3;
           }else {
              main_type = 4; //rr
           }
           root = left_rotate(root);
    }
    printf(" avl maintain %s\n",maintain_str[main_type]);
    return root;
}

// 当前为插入节点操作 ，插入时，不包含这个节点的其他子树，是不可能失衡的,
// 插入时检查调整的过程，其实可以顺着，刚刚insert的节点回溯,判断每个节点
// 是否需要向下调整

Node *insert_Node(Node *root, int key){
    if(root == NIL) return getNewNode(key);
    if(root->key ==key) return root;
    if(key < root->key) {
        root->lchind =insert_Node(root->lchind,key);     
    }else{
        root->rchind =insert_Node(root->rchind,key);
    }
    Update_height(root);
    return maintain(root); 
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
void clear(Node *root){
    if (root == NIL)
        return;
    clear(root->lchind);
    clear(root->rchind);
    free(root);
    return;
}


void output_tree(Node *root){
    if(root== NIL) return ;
    //前序
    printf("(%d(%d)) |  %d , %d\n",root->key,root->height
           ,root->lchind->key,root->rchind->key);
    output_tree(root->lchind);
    output_tree(root->rchind);
    return;
}

Node * rand_insert(Node *root){
    int val =rand() % 100;
    printf("\n insert %d to avl  tree :\n",val); 
    root = insert_Node(root,val);
    output_tree(root);
    return root;
}

int main(){

    srand(time(0));
    int n; 
    scanf("%d",&n);
    Node *root=NIL;
    for(int i =0 ; i < n ;i++){
        root =rand_insert(root);
    }
    clear(root);
    return 0;
}
