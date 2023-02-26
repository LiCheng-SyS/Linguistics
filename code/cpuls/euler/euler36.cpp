#include<iostream>
using namespace std;


int func(int a,int target){
    int arra=a,m=0;
    while(a){
      m=m*target+a%target;
      a/=target;
   }
    return arra ==m;


}


int main(){
    int  ans=0;
    for(int i=1;i<1000000;i++){
        if(func(i,2)&&func(i,10)){
             ans+=i;
        }
    }
    cout << ans <<endl;
    return 0;
}
