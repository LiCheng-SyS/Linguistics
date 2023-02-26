#include<iostream>
using namespace std;

long long  num[10000005];
 long long func(long long x){
        if(x==1){
            return 1;
        }
        if(x<10000000&&num[x]!=0){
              return num[x]; 
        }
        long long t;
        if(x%2 == 0){
          t= func(x/2)+1;
        }else{
            t=func(3* x +1)+1;
        }
        if(x<10000000){
            num[x]=t;
        }
        return t;
   }


int main(){
  long long ans=0 ,mmax=0;
  for(int i=1;i<=10000000;i++){
   long long  t =func(i);
   if(t>mmax){
     mmax =t;
     ans=i;
   }

  }
  cout<< ans <<endl;
return 0;
}




