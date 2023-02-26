#include<iostream>
using namespace std;


int func(int x){
   int raw =x ,t=0;
   while(x){
     t= t * 10+ x % 10;
     x=x/10;
   }
 int reulte =raw==t;
 return reulte;
}



int main(){
    int temp=0;
for(int i=100; i<1000;i++){
        for(int j=i;j<1000;j++){
          if(func(i*j))
          {
             temp=max(temp,i*j); 
          }
      }
    }
    cout << temp << endl;
    return 0;
}

