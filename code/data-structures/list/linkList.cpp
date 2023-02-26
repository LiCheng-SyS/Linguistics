#include<iostream>
#include<stdio.h>
using namespace std;






struct LinkListNode{
    LinkListNode(int data):data(data),next(NULL){};
    int data;
    LinkListNode * next;
};

void list_reverse(LinkListNode *p){
    if(p==NULL)return;
    list_reverse(p->next);
    printf("%d -> ",p->data);
    return;
}

int main(){
  LinkListNode * head =NULL; 
  head =new LinkListNode(1);
  head ->next = new LinkListNode(2);
  head ->next ->next= new LinkListNode(3);
  head ->next -> next -> next = new LinkListNode(4);
  
  list_reverse(head);
  printf("\n");

  LinkListNode * p =head ;
  while(p!=NULL){
    
      cout << p->data << endl ;
      p=p->next;
   }
  cout << endl;
  return 0;
}
