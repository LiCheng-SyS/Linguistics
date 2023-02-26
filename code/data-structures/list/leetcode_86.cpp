#include<iostream>
using namespace std;

struct ListNode {
        int val;
         ListNode *next;
         ListNode() : val(0), next(NULL) {}
         ListNode(int x) : val(x), next(NULL) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * partition(ListNode* head, int x) {
      ListNode  rbig,lsmall,*p1=&rbig,*p2=&lsmall, *p=head,*q; //p为原始链表
      //这个p实际上是指向rbig 的末尾节点 lsmall同理末尾
      while(p){
          q=p->next;
          if(p->val < x){
             p->next = p2->next;//实际上是挂null 最后一位是null
             p2->next = p;  //p接到了 接到第一个链表的最后一位
             p2 =p; //一定是指向 原始链表的最后一个节点的
          }else{
             p->next = p1->next ;
             p1->next =p;
             p1=p;
          }
       p=q;
      }
   p2->next=rbig.next;
   return lsmall.next;
}


int main(){
    ListNode *node = NULL;
    node  =new ListNode(1);
    node->next =new ListNode(4);
    node->next->next =new  ListNode(3);
    node->next->next->next =new ListNode(5);
    node-> next -> next -> next -> next =new ListNode(2);


    ListNode  *node1 =node;
    while(node1)
    {
        cout << node1->val << endl; 
        node1=node1->next;
    }
    cout <<endl;

    ListNode *head=partition(node,3);
    while(head){
        cout << head->val <<endl;
        head = head ->next;
    }
    cout << endl;
     
    
    return 0;
}
