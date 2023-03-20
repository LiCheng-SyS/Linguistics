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
public:
    A(){
        cout << this <<"  default constructor" << endl;
    }
    A(int x){
        cout << this << "  param cpms" << endl;
    }
    A(const A&a){
        cout << "  copy constructor" << endl;
    }
};
  
A  func(){
    A temp(3);   // 代参数的构造
    cout << " temp " <<  &temp << endl;
    return temp;// 这里应该是属于匿名变量拷贝给了 A
}

//按照流程应该是发生了三次构造 ?  为什么输出的解构为什么是同一个地址
// 中间的匿名对象应该没意义的 只是一个中转的功能
// 第一步就吧匿名的临时变量优化掉
// 第二 ->tmep 拷贝给A对象 ，既然是拷贝他们是一模一样，加在temp对象所有的操作都会在去往A上 
//  temp 对象其实可以看做A对象的别名,这就是返回值优化的最终版本
//  最终是 吧temp 当做A对象的引用了
int main(){
    A a =func(); //匿名对象在拷贝A 
    cout  <<" a :"  << &a <<endl;
     return   0;
}
