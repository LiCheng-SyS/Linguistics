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
        cout << this << "  Class A:" << x  << endl;
    } 
    A(const A &a){
        //拷贝构造
        cout << this << "   :copy A" << &a << endl; 
    }
    void operator=(const A &a){
        cout << this << "assign from " << &a << endl;
    }
    int x ;
};



class Data{
public :
    // 接在构造函数后面  : 初始列表（初始化成员）
    //显示性的调用 A的构造函数
    Data():__x(10),__y(0),a(34) {
        cout << "default " << endl;
    }
    int  x(){return __x;}; 
    int  y(){return __y;};

    ~Data(){
        cout  << "Free" <<endl;
    }
private :
    int __x,__y;
    A a;
};
int main(){
    // Data dt;
    // A s(45);
    A a = 45;
    cout << "addressof a :" <<  &a <<endl;
    a  =  78 ;
    //cout <<dt.x() << dt.y() <<endl;
    return 0;
}
