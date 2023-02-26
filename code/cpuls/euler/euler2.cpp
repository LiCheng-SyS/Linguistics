#include<iostream>
using namespace std;

int main(){
    long long temp=0;
    int a=1;
    int b=2;
    while(b<4000000){
        if(b %2==0 ) {
            temp +=b;
        }
        b=a+b;
        a=b-a;
    }
    cout  << temp << endl;
    return  0;
}
