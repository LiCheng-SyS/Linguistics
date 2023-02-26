#include<vector>
#include<iostream>
using namespace std;


class Node{
public :
    int val;
    Node*next,*prep;
    Node(int val=0,Node *next=NULL,Node *prep=NULL):val(val),next(next),prep(prep){}                                      
    void insert_prep(Node *p){
        p->prep =prep; //当前插入节点扽perp = 当前节点prep;
        p->next= this; //插入节点下一位 应该当前节点 
        if(this->prep)this->prep->next=p;
        this->prep=p;
        return ;
    }       
    void inser_next(Node *p){
        p->prep=this; //这个是后面插入了 前一位就是当前节点了
        p->next= this->next; //节点得next 就是节点指向扽一下位了.
        if(this->next) this->next->prep= p;
        this->next =p;
        return ;
    }
    void d_prep(){
        if(this->prep==NULL) return ;
        Node *p =this->prep; // 前一个节点
        this->prep=p->prep;
        if(p->prep)p->prep->next=this;
        delete  p;
    }
    void d_next(){
        if(this->next==NULL)return ;
        Node *p=this->next;
        this->next=p->next;
        if(p->next) p->next->prep=this;
        delete  p;
        return ;
    }
};

int main(){
    Node *node =NULL;    
    cout << "\nTraversal in forward direction \n";
   
    node=new Node(1);
    node->next=new  Node(2);
    node->next->next=new Node(3);
  //  while (node) {
        // cout <<" next" << node->val <<endl;
      //   node=node->next;
  //  }
     cout << endl ;
     
     Node *p=node->next;
     Node *pre=NULL;
     
     while(node){
         //未翻转部分指向翻转的头节点
         node->next =pre;
         pre=node;
         node=p;
         if(p){
             p=p->next;
         }
     }
     
      
     while(pre){
         cout << " prep" << pre->val << endl;
         pre=pre->next; 
     }
     return 0;
}


