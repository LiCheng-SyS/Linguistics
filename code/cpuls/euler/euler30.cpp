#include<iostream>
using namespace std;



int num[15];
//当前方法是吧每个数字的5次方算出来
int init(){
  num[1]=1;
  for(int i=2;i<10;i++){
      int t =i;
      for(int j=0;j<4;j++){
          t*=i; //五次方
      }
      num[i]=t;
      cout << i << ";" << num[i]<< "";
  }
  cout << endl;
}

int func(int x){
    int t=0,rawx=x;
    while(x){
        //x %10 就是最后一位 假设是5的话 ,所有的值+5的5次方 这个数组就是数字的次方
        t+=num[x%10];
        x/=10;
    }
    return x==rawx;
}

int main(){

   init();

   int ans=0;
   for(int i =2;i<1000000;i++){
       if(func(i)){
           ans+=i;
           cout<< i <<endl;
       }
   }
   cout << ans <<endl;
    return 0;
}
