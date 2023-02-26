#include<vector>
#include<iostream>
using namespace std;



bool isValid(string s) {
    int  leftn =0;
    int  len =s.size();
    for(int i=0; i  < len; i++) 
    {
        if(s[i]=='(')leftn++; 
        if(s[i]==')')leftn--;   
        if(leftn >= 0) continue;
        return false; 
    }
    return  leftn==0;
}



int main(){
    string  n = "(((())))";
    if(isValid(n)){
        cout  << " xxx "  << endl;
    }else{
        cout <<" fail" <<endl;
    }
    return  0;
}
