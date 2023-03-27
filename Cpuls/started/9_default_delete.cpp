#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
  
using namespace std;

class A{
  A() = default;  // 隐性的行为显性化
  //A(const A &) =default;  
  A(const A &) = delete; 

  // A() {} 这和上面不是一个东西
};

int main(){
 
  return   0;
}
