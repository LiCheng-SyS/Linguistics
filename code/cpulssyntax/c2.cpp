#include<vector>
#include<iostream>
using namespace std;


struct cmp{
    bool operator()(vector<int> &a, vector<int> &b){
         return  a[0]+a[1]  < b[0]+b[1];
    }
};



int main(){
    cmp cp;
    vector<int> temp1 {1 ,12,35,6};
    vector<int> temp2 {10,24,8,9};


    for(auto v1 : temp1){
        cout  << " tep1   not change"  <<  v1 << endl; 
    }
     
    cout <<endl;
    cp(temp1,temp2);
    
    for(auto val:temp1){
         cout  <<val <<endl;
    }
    cout<<endl;


    for(auto val:temp2){
        cout << val << endl;
    }   
    
    return 0;
}
