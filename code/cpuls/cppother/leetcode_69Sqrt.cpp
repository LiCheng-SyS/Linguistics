#include<iostream>
#include<cmath>
using namespace std;

//x 的平方根
int mySqrt1(int x) {
    return (int)sqrt(x);   
}



int mysqlt(int x){
   long long l=0,r=x;
   while(l!=r){
       int mid = (l + r + 1) / 2;
       if(mid * mid <=x ){
            l= mid ;
       }else{
            r= mid -1;
       }  
   }
   return r;
}   


int  main(){
     
    cout << mysqlt(8) << endl;
    cout << mySqrt1(8)<< endl;
    return 0;
}
