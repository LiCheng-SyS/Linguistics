#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#include<cstdlib>

using namespace std;
//多继承 限定类的功能  不允许 被拷贝
#define  BEGINS(x) namespace x {
#define  ENDS(x) }

BEGINS(test1)
    //功能类的用途: 用于标记类的性质
    class uncopy{
        // 所有的派生类的 copy 构造都会删
    public :  
        //uncopy()= delete ;
        uncopy(const uncopy & ) = delete ;
        uncopy  &operator=(const uncopy &) =delete; 
        uncopy  &operator=(const uncopy &)const =delete; 
    protected :
        uncopy()= default ;
    };

class A: public uncopy{}; 

int main(){
    A a;
    A b; 
    // b = a;// no 赋值运算被删除
    // A c(a)/// 拷贝构造被删除
    return  0;
}
ENDS(test1)


BEGINS(test2)
class HAS_XY{
public :
   int x , y; 
};

class HAS_XYZ : public  HAS_XY{
public :  
    int  z ; 
};

class A :public HAS_XY {
public : 
    A () {x=y=1;}
};

class B :public HAS_XY {
public:
    B () {x=y=2;}
};

class C :public HAS_XYZ {
public : 
    C (){ x = y = z = 3; }

};
class D :public HAS_XYZ {
public :
    D (){ x = y = z = 4; }
};
class E :public HAS_XY {
public:
    E () {x=y=5;}
};

void func(HAS_XY &a){
    cout << " HAS_XY " << endl;
    cout <<a.x << endl;
}

void func(HAS_XYZ &a){
    cout <<" HAS_XYZ" << endl;
    cout << a.x << ", "  << a.x << " ,"<< a.z << endl;
}

int main(){
    A a;
    B b;
    C c;
    D d;

    func(a) ,func(b) ,func(c),func(d);
    return 0;
}
ENDS(test2)

int main(){
    test2::main();
     return 0;
}
