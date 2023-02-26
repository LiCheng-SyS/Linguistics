#include<iostream>
#include<algorithm>
#include<vector>  


//需要连续地址空间

using namespace std;



class Queue{
   public :
       Queue(int n = 10 ) : arr(n),head(0),tail(0),cnt(0){}
       //默认大小
       void push(int x){  
           //如果做PUSH 头指指针 和尾指针都应该到最前面
           //值指向tail  并且tail应该指向下一位
           //tail 实际就是最后一个元素的的下一位
            if(full()) return ;
            arr[tail]=x;
            tail+=1;
            cnt+=1;
            if(tail == arr.size()) tail=0;
//            cout << tail <<  head << endl;
            return ;
       };//入队
       void pop(){
           //头指针 向后一位  
           if(empty()) return ;
          head+=1;
          cnt-=1;
          if(head ==arr.size()) head=0;
          return;
       };//出队

       bool empty(){
            //tail 是last +1   当前总元素=  tail- head  而Queue存储结构一般为左闭右开
            // 队列是否为空 判断 是否tail == head
            return cnt == 0;
       };// 判断队列是否为空
       int front() {
            return arr[head];
       }; //判断首元素

       bool full(){
        //书上一般说 ->满了？ 尾+1  = 头指正则满    
        // MS也是同样维护了
        ////tail 指向了最后一位 则整个数组满了  
         return cnt == arr.size();
       };//队列是否满

       int  queuesize(){
          return cnt;
          //  return size;
       };
       void outputqe(){
           for(int i =0,j= head; i< cnt; i++){
               cout <<" j :" <<arr[j] << " ";
               j+=1;
               if(j==arr.size()) j=0;
           }
            cout << endl;
            return ;
       }
       void Clear(){
           if(cnt !=0){
               arr.clear();
               size =0;
           }
         tail=0;
         head=0;
         return ;
       }
   private:
        int head ,tail,size,cnt;//元素数量 ==数组大小的时候满了
        vector<int>arr;

};

int main()
{
   int op , val;
   Queue qe(5);
   while(cin >>op){
       switch(op){ 
       case 1 :{
                 cin >> val;  
                 qe.push(val);
               }break;
       case 2 :{
                 qe.pop();
               }break;
       case 3 :{
                cout << "size : " <<  qe.queuesize() <<endl;
               }break;
       }
   //  cout <<  "queue size " << qe.queuesize() <<endl;
     qe.outputqe();
   }
   
   return  0;
}


