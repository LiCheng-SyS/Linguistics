#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<algorithm>
#include<cstdlib>
  
using namespace std;
  
#define BEGINS(x) namespace x{
#define ENDS(x) }  //endl namespace 

/* 虚函数表   */
BEGINS(test1)
//标识了 virtual 则前 8 位在前 
class Base{
public :
    virtual void func(){
        cout << "base func " << endl;
    }
    virtual void func1(){
        cout << "base func1 " << endl;
    }
    virtual void func2(){
        cout << "base func2 " << endl;
    }

        virtual ~Base(){ }
};


// A 的头八个字节是 虚函数表占用的位置, int 为 四字节  像高位进行对齐w
//16 是对齐出来的
class A :  public Base {
public : 
    int x ;
    void func2() override{
        cout << "A func2" <<endl;
    }
};

class B : public Base  
{
public :
    //整形变量  4字节
    int x ;
    void func() override{
        cout <<" B  func" << endl; 
    }
    void func1() override{
        cout <<" B func1" <<endl;
    }
};


typedef void (*func)();
int main(){
    cout << " Base : " <<sizeof(Base)   << endl;
    cout << " A : " <<sizeof(A)   << endl;
    cout << " b "  << sizeof(B) << endl;
    cout << "---------------------------------------" << endl;

    A a;
    B b;
    a.func();
    a.func1();
    a.func2();

    b.func();
    b.func1();
    b.func2();
    cout << "---------------------------------------" << endl;
    
    //函数地址的概念: 取出func **的首地址,虚函数表的第一项就是需要调用的函数
    ((func **)(&a))[0][1]();
    //((func **)(&a))[0][0]=((func **) (&a))[0][1];
    cout <<" x"  << endl; 
    swap(((func **) (&a))[0],((func **)(&b))[0]);
    //在此处我交换了虚函数表,在此段的代码中可以证明：
    //虚方法是在运行时场景下生成
    ((func **)(&a))[0][1]();
    //// --output b func1
    return  0;
}

ENDS(test1)

BEGINS(test2)
//这个成员方法的this 指针是指向当前对象的  （意味着他是个变量，这个变量是运行时会被自动赋值的）
class Base{
public :
    virtual void func(int x ){
        cout << this << "base func " <<  x <<endl;
    }
    virtual void func1(){
        cout << "base func1 " << endl;
    }
    virtual void func2(int x ){
        cout  <<  this  << "    base func2   : " << x  << endl;
    }
     virtual ~Base(){ }
};

class A :  public Base {
public : 
    int x ;
    //实际上如果用c 原生的函数指针来调会出现问题
    //因为 调的时候 函数原型应该长这样 func2（this ，int)
    void func2(int x ) override{
        cout <<"this->x" << this->x <<endl;
        cout  << this << " :A func2   : " << x << endl;
    }
};
//如果想正常调用成员方法，需要给个void *
typedef void (*func)(void *,int );
int main(){
    A a  , b;
    a.x =1000;
    b.x =100000;
   // a.func2(123);
    //在原生的函数指针传参出了问题,实际吧地址传给了this指针 
    ((func **)(&a))[0][0](&a,123);
    ((func **)(&a))[0][0](&b,123);
    return  0;
}
ENDS(test2)


// dynamic_pointer_cast 懒得建了 写一块算球
//动态类型转换， 父类类型的指针，到子类的类型转换
BEGINS(test3)
    //base 不是多态????
    // 多态情况都是记录了一个virtable的,
    class Base{
    public: 
        //规范 ：父类的析构函数标记为虚方法，从而生成出virtable ,dynamic_pointer_cast，报错解决 
        virtual ~Base(){}
    };
    class a :public Base{};
    class b :public  Base{};
    class c :public  Base{};

int main(){
    srand(time(0));
    Base *p;
    switch(rand() % 4 ){
        case 0:p=new a(); break;
        case 1:p=new b(); break;
        case 2:p=new c(); break;
        case 3:p =nullptr ;break ;
    }
    //只要将x 对象的首地址改了（洗方法）命中不到 ,cast将匹配不到这个条件
    
    //修改头八位地址,修改了虚函数表
    // 实际上cast  是在对虚函数表的 -1 （这一位记录着类型） 进行判断当前类型是什么类型
    a a1;
    if(p) 
        ((void **)(p))[0]  = ((void **)(&a1))[0];
    if(dynamic_cast<a *>(p)!=nullptr){
        //指向p指向 a对象 为真
        cout <<"p is a" << endl;;
    }else    if(dynamic_cast<b *>(p) !=nullptr){
        cout <<"p is b " << endl;
    }else if(dynamic_cast<c *>(p) !=nullptr){
        cout << "p is c " <<endl;
    }
    return 0;
}

ENDS(test3)
int main(){
 
   test3::main();
   return 0;
}
