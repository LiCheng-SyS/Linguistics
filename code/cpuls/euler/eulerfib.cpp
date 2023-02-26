#include<iostream>
using namespace std;


//前50项
long long num[50]={1,1};
int main(){
    for(int i=2;i<=50;i++){
      num[i]=num[i-1]+num[i-2];
    }
    for(int i=1;i<50;i++){
        cout<<i<< ": " <<num[i] <<endl;
    }
    return 0;
}

