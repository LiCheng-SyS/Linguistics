#include<iostream>
using namespace std;


long long n ,m ,num[10000005],rawr;

long long func(long long mid){
      int t =0;
      for(int i=0;i<n;i++){
          if(num[i]> mid){
             //程度必须是大于预设高度的值的
             //如果是
              t+=num[i]-mid;
          }
      }
      return t;
}

 //m是要求的程度
long long bs(){
   long long l=0,r=rawr;//原始的右
   while(l!=r){   
   long long mid=(l+r+1)/2;
   long long s=func(mid);//切出的总数？
   if(s>=m){
       l=mid;
   } else{
       r=mid-1;
   }
 }
   return  l;
}
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> num[i];
        rawr=max(rawr,num[i]);
    }
    cout << bs()<< endl;
        
    return  0;
}
