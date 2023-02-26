#include<iostream>
#include<string>

#include<stack>
using namespace std;


int main(){
    string input;
    getline(cin,input);
    stack<char> s;
    for(int i=0;i<input.size();i++){
    
        s.push(input[i]);
        
        while(!s.empty())
        { 
          cout << s.top()<<endl;   
          s.pop();
        }
    }
    return 0;
}
