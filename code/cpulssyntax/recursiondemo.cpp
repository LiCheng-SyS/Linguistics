#include<vector>
#include<iostream>
using namespace std;

void up_and_down(int );

int fib(int n){
    if(n<=2) return n;
    return fib(n-1)+fib(n-2);
}

int main(){

    up_and_down(1);
    return 0;
}

void up_and_down(int n){
   cout << "level " << n << "   locaction " << &n <<endl;
   if(n<5)
   up_and_down(n+1);
 //  fib(n+1);
    cout << "LEVEL " << n << "  locaction " << &n <<endl;
}
