#include<iostream>
using namespace std;
void func(int *n1, int *n2){
    //n2可能比N1短先更新长度
   n2[0]=n1[0]; //更新长度 先给数字的长度
   for(int i=1;i<=n2[0];i++){
       n2[i]+=n1[i];
       if(n2[i]>9){
           n2[i+1]+=n2[i]/10;
           n2[i]%=10;
           if(i==n2[0]){
               //最高位变化
                n2[0]++; 
           }
       }
   }
}
int main(){  
   int num[2][1111]={{1,1},{1,1}},a=1,b=1;
       for(int i=3;1;i++){
       //这个一直会计算下去 1 为真
       //两个数组相加
           func(num[a],num[b]);
           if(num[b][0]>=1000){
              cout<< i <<endl;
       //这是项数
              break;
           }
           //如果没有就交换值接着+
            swap(a,b);
          }

    return 0;
}
