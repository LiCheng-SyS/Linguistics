#include<vector>
#include<iostream>
using namespace std;




string removeOuterParentheses(string s) {
    string ret;
    for(int i =0,pre=0,cnt=0; i<s.size();i++)
    {
        //pre 记录是实际上是当前( 括号的起始位置
        //cnt 记录左右括号的差值
        if(s[i]=='(') cnt+=1;
        else cnt-=1;
        if(cnt !=0) continue;
        ret+= s.substr(pre+1,i-pre-1);
        pre = i+1;
    }
    return ret;
}

int main(){


    return 0;
}


