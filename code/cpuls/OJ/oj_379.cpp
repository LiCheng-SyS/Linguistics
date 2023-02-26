#include<iostream>
#include<string>
#include<stack>
using namespace std;


stack<int>sta_cnt;
stack<int>sta_max;
int n;
int main(){
   
   cin >> n;
   for(int i=0;i<n;i++){
       int  temp = 0;
       if(temp==0){
            cin>> temp;
            sta_cnt.push(temp);
            if(sta_cnt.size()==1){
               sta_max.push(temp);
            }else {
                //第二次进来 cnt果不是第一波入栈,如果需要和第一次push进来的值进行比较
                //取极大值为栈顶   
                
                sta_max.push(max(sta_max.top(),temp));
               /// cout << sta_max.top() <<endl;
            }
       }else if(temp ==1){
           //如果遇到1 则不为空  则出栈.
           if(!sta_cnt.empty()){
               sta_cnt.pop();
               sta_max.pop();
        }
       }else if(temp==2){
           // 由于二可能是最后一位 单独拎出来判断 如果直接输出栈顶元素
           if(!sta_max.empty()){
               cout <<  sta_max.top()<<endl;
           }else{
               cout << 0<< endl;
           }
            
       }
   }
  return 0;
}
