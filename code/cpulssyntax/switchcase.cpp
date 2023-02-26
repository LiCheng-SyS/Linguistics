#include<vector>
#include<iostream>
#include<stack>
using namespace std;

stack<char> s1;
bool isValid(string s) {
   // stack<char> s1;
    for(int i=0;i<s.size();i++){
        switch(s[i]){
        case '(' :
        case '[' :
        case '{':s1.push(s[i]);
        }
    }
 return !s1.empty();    
}

int main(){

    string temp="({}[]";
    if(isValid(temp)){
        cout << "xxx" <<endl;
        while(!s1.empty()){
        
            cout <<" s1" <<s1.top()<<endl;
            s1.pop();
        }
    }
    
    return 0;
}
