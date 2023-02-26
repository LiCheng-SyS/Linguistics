#include<iostream>
#include<algorithm>
#include<vector>  


//需要连续地址空间

using namespace std;



class Queue{
   public :
       Queue(int n = 10 ) : arr(n){}
       //默认大小
       void push(int x){  
           //如果做PUSH 头指指针 和尾指针都应该到最前面
           //值指向tail  并且tail应该指向下一位
           //tail 实际就是最后一个元素的的下一位
            if(full()) return ;
            arr[tail]=x;
            tail+=1;
            size++;
            cout << tail <<  head << endl;
            return ;
       };//入队
       void pop(){
           //头指针 向后一位  
           if(empty()) return ;
          head+=1;
          size--;
          return;
       };//出队

       bool empty(){
            //tail 是last +1   当前总元素=  tail- head  而Queue存储结构一般为左闭右开
            // 队列是否为空 判断 是否tail == head
            return tail==head;
       };// 判断队列是否为空
       int front() {
            return arr[head];
       }; //判断首元素

       bool full(){
        ////tail 指向了最后一位 则整个数组满了  
         return tail == arr.size();
       };//队列是否满

       int  queuesize(){
          return tail- head;
          //  return size;
       };
       void outputqe(){
           for(int i =head; i< tail; i++){
               cout << arr[i] << " ";
           }
            cout << endl;
            return ;
       }
   private:
        int head ,tail,size ;
        vector<int>arr;

};

int main()
{
   int op , val;
   Queue qe(5);
   while(cin >>op >>val){
       switch(op){ 
       case 1 :{
                 qe.push(val);
               }break;
       case 2 :{
                 qe.pop();
               }break;

       }
   //  cout <<  "queue size " << qe.queuesize() <<endl;
     qe.outputqe();
   }
   
   return  0;
}


