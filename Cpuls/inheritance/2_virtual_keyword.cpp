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
//C++中类的菱形继承问题  关键字virtual  
// 多继承的问题
#define BEGINS(x)namespace x{
#define ENDS(x)} //namespace

BEGINS(test1)
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
ENDS(test1)

BEGINS(test2)
class Base{
   public :  
       Base():num(100){}
       int  num;
};

class A :virtual public Base
{
public:
    void setnum(int x ){
        cout << " set num : " << &(this->num) << endl; 
        this->num = x;
        return ; 
    }
};

class B :virtual public Base{
public : 
    int  GetNum(){
        cout <<" getnum ：" <<&this->num << endl;
        return this->num ;
    }
};

class C :public B , public A {};
int main(){
    C c1;  
    cout << c1.GetNum() << endl;
    c1.setnum(10000);  
    cout << c1.GetNum() << endl;
    // 由于子类内存分布的特点 C 包括（B A ） [而B 和 A ] 同时都拥有BASE  在底层的出现了相同的基类, 需要用virtual 进行合并
    // set num 和 get num的实际上的内存地址并不是指向一个地方的，本质是上他是操作的两片内存
    return 0;
}
ENDS(test2)


BEGINS(test3)

class NotObj{
public :
    //如果想要斩草除根 不允许申请对象 需要吧拷贝构造和构造一起删掉
    NotObj() =delete;
    NotObj(const NotObj &) = delete ;
};


int main(){
//  NotObj *p=(NotObj *) malloc(sizeof(NotObj));
//   NotObj n(*p); //拷贝构造？
//  cout << &(n) << endl;
   return 0 ;
}

ENDS(test3)

int main(){
   test3::main();
  //test2::main();
  //test1::main(); 
  return 0;
}
