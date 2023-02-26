#include<iostream>
using namespace std;


int climbStairs(int n) {  
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    } 

    int ans[2]={1,2},a=0 ,b=1;
    for(int i =2; i<=n;i++){
         ans[a]+=ans[b];
         cout << a << b << endl;
         swap(a,b);
    }
     return ans[a];
}


int  main(){

    cout << climbStairs(3)<<endl;

    return 0;
}



