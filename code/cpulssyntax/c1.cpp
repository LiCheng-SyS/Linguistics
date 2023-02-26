#include<vector>
#include<iostream>
using namespace std;




int d2(){
    int i =0;
    cout << i++ << " i++ " <<endl;
    return i ;
}

int d1(){
   int i=0;
   cout << " ++i" << ++i << endl;
   return i;
}



int main(){
    int arr[100]={1,2,3,1};
   
    int cnt =1,temp=1;
    arr[cnt++]=2;
    cout << cnt <<endl;
   // while(cnt && temp){
       // cout << temp <<endl;
     //   temp=0;
   // }

    return 0;
}
