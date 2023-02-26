#include<iostream>
using namespace std;

//第一步 每个节点后面插入复制节点
class  Node{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
   }

Node* copyRandomList(Node* head) {
      if(head==NULL) return NULL;
      Node *p =head, *q;   // q =复制的节点  
      while(p) //全部复制出来
      { 
        q= new Node(p->val);
        q->random=p->random;  //复制的节点 和源节点  指向一个节点 
        q->next=p->next;  //q的下一位 应该插入p的下一位、
        p->next=q; // p的节点挂q
        p=q->next;
      }               // 这里的目的就是将 q 放在p的后面
      p=head->next; //code 到达这里为复制出来的节点
      while(p){
        if(p->random) p->random=p->random->next;
        p=p->next;
        if(p) p=p->next;
        p= p->next->next; 
      }
     //此刻修正了 random 的指针
      
      //拆分
      
      Node *n_head =head->next;
      p=head;
      while(q){
           q=p->next;
           p->next = q->next;
           if(p->next) q->next=p->next->next;
           p= p->next;

      }
      return n_head;
  }
    
};

int main(){


    return 0;
}

