#include<vector>
#include<iostream>
#include<stack>
using namespace std;



bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
     stack<int> s1;
     //判断出 栈序列是否能被满足
     //i 指向 出栈序列中的第i位,j是指向的入栈中的位子
     //核心 就是判断栈顶元素是否等于将要出栈的的元素 
     for(int i=0,j=0;i<popped.size();i++){
         while(j<pushed.size() &&(s1.empty()||s1.top()!=popped[i])){
            s1.push(pushed[j]);
            j+=1;
         }
     
     if(s1.top()!=popped[i])return false;      //前面已经将不等于的入栈了 
     //如果还不等于 这里将应该是flse了
     s1.pop();
    }
     return true;
}



int  main(){
    return 0;
}
