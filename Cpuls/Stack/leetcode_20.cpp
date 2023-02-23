#include<vector>
#include<iostream>
#include<stack>
using namespace std;



bool isValid(string s) {
    stack<char> s1;
    for(int i=0;i<s.size();i++){
        switch(s[i]){
        case'(':
        case'[':
        case'{':s1.push(s[i]);  break;
        case')':if(s1.empty()||s1.top()!='(')return false;s1.pop();
        case']':if(s1.empty()||s1.top()!='[')return false;s1.pop();
        case'}':if(s1.empty()||s1.top()!='{')return false;s1.pop();
        }
    }
    return s1.empty();
}



int main(){

    return 0;
}
