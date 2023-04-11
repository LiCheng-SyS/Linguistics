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
public :
    A(){
        cout << " default" << endl;
    } // 一旦有带参数的构造器,如果没有调用按照规则调用构造函数的参树，则会报错 需要显示指出构造函数
    A(int x):x(x){
        cout << this << "  Class A:" << x  <<endl;
    }   
    A(const A &a){
        //拷贝构造
        cout << this << "   :copy A" << &a <<endl; 
    }   
    int x ; 
};


int main(){

 A a=45;
 cout << "addressof a :" <<  &a <<endl; 
 
 return 0;
}
