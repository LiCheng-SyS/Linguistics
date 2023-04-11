#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>

using namespace std;
//C++中类的菱形继承问题  关键字virtual  

class Base_q{
public:
    Base_q(){
        x = 1067;
    }
    int x;
};

class A:public virtual   Base_q {};
class B:public virtual  Base_q {};
class D:public A , public B{};

int main(){
    D d;
    d.B::x = 1;
    d.A::x = 1;
    d.x = 178;
    cout << d.A::x <<endl;
    cout << d.B::x <<endl;
    cout << d.x <<endl;

    cout << "sizeof " <<endl;
    return 0;
}
