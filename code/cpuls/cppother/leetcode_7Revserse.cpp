#include<iostream>
 #include <climits>
using namespace std;


int Reverse(int x){
   int temp= 0;
   if(temp >  INT_MAX / 10 || temp< INT_MIN  / 10|| 
     (temp==  INT_MAX / 10 && x % 10 > 7)||
     (temp==INT_MIN /10 && x % 10 < -8)) 
   {
   temp =0 ;
   return  0;
   }
   while(x){
    temp =temp * 10 + x % 10;
    x/=10;
   }
   return temp;
}

int main(){
    cout << INT_MIN << endl;
    cout << INT_MAX << endl; 
    int x=  Reverse(-12345);
    cout << x << endl;
    return 0;
}
