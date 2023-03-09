#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using namespace std;

typedef  struct Node{
    int key;
    int color; //0 red , 1 ,black , 2doublue black
    struct Node *lchind,*rchind;   
}Node;
Node __NIL;
#define  NIL (&__NIL)
__attribute__((constructor))
    void init_NIL() {
        NIL->key = -1;
        NIL->color = 1;
        NIL->lchind = NIL->rchind = NIL;
        return ;
    }

Node *getNewNode(int);
Node *left_rotate(Node *);
int has_red_chind(Node *);
Node *right_rotate(Node *);
Node *insert_maintain(Node *);

Node *__insert(Node *,int );
Node *insert_Node(Node *, int);
Node *rand_insert();
void output(Node *);

Node *earse(Node * , int );
Node *predecessor(Node *);
Node *__earse(Node *,int );
Node *earse_maintain(Node *);

Node *getNewNode(int key){
    Node *p=(Node *)malloc(sizeof(Node));
    if(p==NULL){
        printf("Failed to allocate memory.\n");
        exit(1);
    }
    p->key = key;
    p->color=0;
    p->lchind =p->rchind =NIL;
    return p;
}

int has_red_chind(Node *root){
    return root->lchind->color ==0 || root->rchind->color ==0;
}

Node *left_rotate(Node *root){
    printf(" left _rotate %d\n",root->key);
    Node *temp = root->rchind;
    root->rchind =temp->lchind;
    temp->lchind =root;
    return temp;
}

Node *right_rotate(Node *root){
    printf(" right_rotate %d\n",root->key);
    Node *temp = root->lchind; 
    root->lchind =temp->rchind ;
    temp->rchind = root;
    return temp;
}

const char  *stropt[]={"","LL","LR","RL","RR"};
Node *insert_maintain(Node *root){
    if(!has_red_chind(root)) return root;
    //两个子孩子都为红色
    if(root->lchind->color == 0 && root->rchind->color==0){
        if(!has_red_chind(root->lchind) && !has_red_chind(root->rchind)) return root;
        //当前为最简单的情况1 当前孙子都不为red ,则不需要调整，跳出去 
        printf(" 情况1\n");
        root->color = 0 ;
        root->lchind->key =root->rchind->key =1;
        return root;
    }
    if(root->lchind->color ==0 && !has_red_chind(root->lchind))return root;
    if(root->rchind->color ==0 && !has_red_chind(root->rchind))return root;
    printf("情况2\n");
    //情况2 
    int flag = 0;
    if(root->lchind->color ==0){
        //左子树为红 ll
        if(root->lchind->rchind->color == 0){
            root->lchind =left_rotate(root->lchind);
            flag =2;
        }else{
            flag =1;
        }
        root=right_rotate(root);
    }else{
        if(root->rchind->lchind->color ==0){
            root->rchind =right_rotate(root->rchind);
            flag = 4;
        }else{
            flag = 3;
        }
        root=left_rotate(root);
    }
    printf("Maintain type :%s\n",stropt[flag]);
    root->color = 0;
    root->lchind->color = root->rchind->color =1;
    return root; 
}
Node *__insert(Node *root ,int key){
    if(root == NIL)return getNewNode(key);    
    if(root->key == key )return root;
    if(key < root->key){
        root->lchind = __insert(root->lchind,key);
    }else{
        root->rchind= __insert(root->rchind,key);
    }
    return insert_maintain(root);
}

Node *insert_Node(Node *root, int key){
    root=__insert(root,key);
    root->color = 1;
    return root;
}


void clear(Node *root){
    if(root ==NIL) return ;
    clear(root->lchind);
    clear(root->rchind);
    free(root);
    return ;
}

void print(Node *root){
    printf("(%d | %d ,%d, %d )\n",
           root->color,root->key,
           root->lchind->key,root->rchind->key
          );
    return ;
}
void output(Node *root){
    if(root==NIL)return;
    print(root);
    output(root->lchind);
    output(root->rchind);
    return;
}

Node *rand_insert(Node *root){
    int val =rand() % 100;
    printf("insert %d to black tree : \n",val);
    root =insert_Node(root,val);
    output(root);
    return root;    
}
//查找前驱
//前驱为左子树中最右的节点
Node *predecessor(Node *root){
    Node *temp = root->lchind;  
    while(temp->rchind !=NIL){
        temp = temp->rchind ;
    }  
    return temp;
}

//删除保持
Node *earse_maintain(Node *root){
    if(root->lchind->color !=2 && root->rchind->color !=2 )
        return root;
    //当前的根下面必然是有 双重黑节点的 
    // situation1 兄弟节点是红色的
    
    if(has_red_chind(root)){
         printf("Situation 1  brother this red\n");
        // search red root -> left | right
        int flag = 0 ; 
        //目标:新的root 挂黑 ，原始的root 挂红
        root->color = 0;
        if(root->lchind->color == 0){ 
            root =  right_rotate(root);
            flag = 0;
           //双重黑，下沉右子树
        }else{
           root =left_rotate(root);
           flag = 1;
           //双重黑，下沉到左子树
        }
        root->color = 1; 
        if(flag == 0) root->rchind =earse_maintain(root->rchind);
        else root->lchind = earse_maintain(root->lchind);
        return root;
       //以上为 第一种简单的调整情况 ，兄弟节点都为红色
    }
       //右子树 | 左子树 兄弟子树也没有子节点
    if((root->lchind->color ==2 && !has_red_chind(root->rchind)) ||
      (root->rchind->color ==2 && !has_red_chind(root->lchind))) {
        printf("Situation 2  change colo done\n");
             root->color += 1;
             root->lchind->color-=1;
             root->rchind->color-=1;
             return root;
    }
    int maintain_type = 0; 

    //如果右树是双重黑
    if(root->rchind->color ==2){
        root->rchind->color =1;
        //说明第一个字母L     
        //判断调整类型 LR-> LL
        if(root->lchind->lchind->color !=0 ){ 
             // LR 类型的调整,先朝左旋
            root->lchind->color=0;
            root->lchind =left_rotate(root->lchind);
            root->lchind->color = 1;
            maintain_type = 2;
        }else{
            maintain_type = 1;
        }
        root = right_rotate(root);
        //新的根改为原根的颜色,新根节点是左子树,原根节点是右子树
        root->color =root->rchind->color;
    }else{
          root->lchind->color =1;
           //R
          if(root->rchind->rchind->color !=0 ){  
               // RL 类型的调整,先右旋 
              root->rchind->color=0;
              root->rchind =right_rotate(root->rchind);
              root->rchind->color = 1;
              maintain_type =3;
          }else{
              maintain_type =4;
          } 
          root = left_rotate(root);
          //新的根改为原根的颜色,新根节点是右子树,原根节点是左子树
          root->color =root->rchind->color;
    }
    root->lchind->color = root->rchind->color =1;
    //兄弟节点是黑色,且兄弟节点下没有红色节点
    printf("Maintain type :%s\n",stropt[maintain_type]);
    return  root;
}


Node *__earse(Node *root , int key){
    if(root == NIL) return NIL;
    if(key < root->key){
        root->lchind=earse(root->lchind,key);
    }else if(key > root->key){
        root->rchind=earse(root->rchind,key);
    }else{
        //删除当前节点了 两个分支->三种情况
        // situation 1
        //  度为1  --------------度为0的情况-------
        if(root->rchind ==NIL || root->lchind ==NIL){
            // 做删除节点时,需要找到唯一的子节点
            Node *temp = root->lchind == NIL ? root->rchind :root->lchind; 
            //如果root 为红色 ，则并没有更改唯一子孩子的颜色
            //如果root 为黑色 , 则边会变为双重黑
            temp->color += root->color ;
            free(root);
            return temp;
        }else{
            //删除度为2的节点
            Node *temp =predecessor(root);
            root->key = temp->key;
            root->lchind =__earse(root ->lchind , temp->key);
        }
    }
    return earse_maintain(root);
}

Node *earse(Node *root, int key){
    printf("\nearse %d from red black tree \n",key);
    root= __earse(root,key);
    root->color =1 ;
    cout << endl;
    output(root);
    print(root);
    return root;
}

int main(){
    int n; 
    scanf("%d",&n);
    Node *root = NIL;
    for(int i =0 ; i < n ;i++){
        root =rand_insert(root);        
    }
    while(~scanf("%d",&n)) {
         root =earse(root,n);
    }
    clear(root);
    return 0;

}
