#include<vector>
#include<iostream>

using namespace std;


//链表的双端队列
class Node{
public :
    int  val;
    Node *next,*prep;
    Node(int val=0,Node *next=NULL,Node *prep=NULL):val(val),next(next),prep(prep){}
    void insert_prep(Node *p){
        p->prep =prep; //当前插入节点扽perp = 当前节点prep;
        p->next= this; //插入节点扽下一位 应该当前节点 
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
        this ->prep=p->prep;
        if(p->prep)p->prep->next=this;

        delete  p;
        return ;
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


class Dqueue{
public :
    int cnt;
    Node head, tail;
    Dqueue():cnt(0){
        head.next=&tail ;
        head.prep=NULL;
        tail.next=NULL;
        tail.prep =&head;
    }
    //后面
    void  push_back(int val){
        tail.insert_prep(new Node(val));
        cnt +=1;
        return ; 
    }
    //前面
    void  push_front(int val){
        head.inser_next(new Node(val));
        cnt +=1;
        return;
    }
    int  pop_front(){
        if(isEmpty())return -1; 
        //头节点的下一个因为是双头的
        int ret=head.next->val;
        head.d_next();
        cnt-=1;
        return ret;
    }
    int pop_back(){
        if(isEmpty())return -1 ;
       // int ret=head.next->val;
        int ret=tail.prep->val;
        tail.d_prep();
        cnt-=1;
        return ret;
    }
    //是否为空;
    bool isEmpty()
    {
        return head.next=&tail;
    }
    int size(){
        return cnt;
    }

    int front(){
        return head.next->val;
    }

    int back(){
        return tail.prep->val;
    }

};

class FrontMiddleBackQueue {
   public:
    Dqueue q1, q2;
    FrontMiddleBackQueue(){}
    void pushFront(int val) {
        q1.push_front(val);
        //更新元素数量
        updatesize();
        return ;
    }
    void pushBack(int val){
        q2.push_back(val);
        updatesize();
        return ;
    }

    void pushMiddle(int val){
        //如果q1 的数量b q2 多先挪一个过去
        if(q1.size()>q2.size()){
            q2.push_front(q1.back());
            q1.pop_back();
        }
        q1.push_back(val);
        updatesize();
        return ; 
    }


    int popFront() {
        if(isEmpty())return -1;
        int ret = q1.pop_front();
        updatesize();
        return ret;
    }

    int popBack() {
        if(isEmpty())return -1;
        int ret =q2.pop_back();
        updatesize();
        return ret;
    }

    int popMiddle() {
        if(isEmpty()) return -1;
        int ret = 0;
        if(q2.isEmpty()){
            ret = q1.pop_back();
        }else{
            ret =q2.pop_back(); 
        }
        //int ret=q1.pop_back();
        updatesize();
        return ret;
    }     

    bool isEmpty(){
        return q1.size() + q2.size()==0;
    }
    void updatesize(){
        if(q1.size() < q2.size()){
            q1.push_back(q2.front());
            q2.pop_front();
        }
        if(q1.size()==q2.size()+2){
            q2.push_front(q1.back());
            q1.pop_back();
        }
        return;
    }
};




