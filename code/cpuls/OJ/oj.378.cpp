#include<iostream>
#include<stack>
#include<string>

using namespace std;


int main(){
    string s; 
    cin >> s;
    stack<char> sta;


    for(int i=0;i<s.size();i++)
    {
     if(s[i]=='('||s[i]=='{'||s[i]=='[' )
     {
       sta.push(s[i]);
     }else if(s[i]==')'){
        if(!sta.empty() && sta.top()=='('){
             sta.pop();
     }  else{
            cout << "no" <<  endl;
            return 0;
        }
    }
    else if(s[i]==']')
    {
        if(!sta.empty() && sta.top()=='['){
            sta.pop();
        }else {
            cout << "no" <<endl;
        }
    }else if(s[i]=='}')
    {
        if(!sta.empty()&& sta.top()=='{'){
            sta.pop();
        }else{
            cout<< "no" <<endl;
        }
    }

      cout << "YES" <<endl;
    
    }
  

    return 0;
}
