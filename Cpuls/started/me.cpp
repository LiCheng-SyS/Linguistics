#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
  
  
using namespace std;

namespace  x{
class A{
  int a; 
  double b;
  float x;
  void say();
};
  
void A::say(){
    cout << " hello world " << endl;
 }
}
int main(){
    
    cout <<  sizeof(x::A) <<endl;
 
 return   0;
}
