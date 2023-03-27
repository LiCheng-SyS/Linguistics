#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include<functional>
#include <algorithm>
using namespace std;

#define BEGINS(x) namespace x{
#define ENDS(x) }//end of namespace x

BEGINS(test)
class Point{
public:
    Point(int x , int y):x(x),y(y){}
    void output(){
        cout << "inner " << " x" << x  << " y" << y <<endl;  
        return ;
    }
    Point  operator+(int x )const { 
         //这是的临时对象,这就不返回引用
        return    Point (this->x + x, this->y+ x);  
    }
    Point &operator+=(int x){ 
         //当前操作符重载,将当前obj 返回到到引用上去
         //如果返回的是值（operator）的话，他会将值copy 一份出来给临时对象
        this->x += x;
        this->y += x; 
        return * this; 
        //返回地址(&operator) 对象并没有发生变化,当前的值作用还是自身的对象
    }
    //如果有额外的参数，就是后 ++ 如果没有额外的参数就是前++ --等逻辑等同
    Point   operator++(int){
        //单目运算符,实现自身的值+1 ,然后返回+1之前的值 
         Point ret(*this);
         this->x += 1;
         this->y += 1;
         return ret;
    }
    //前++ 
    Point  &operator++(){
        //单目运算符,前++ 是直接对其地址+1 ,然后+1的值 
         this->x += 1;
         this->y += 1;
         return *this;
    }     

    friend void output(Point &);
    friend ostream &operator<<(ostream &,const Point &);
    friend  Point operator+(const Point &,const Point &);
private:
    int x, y;
};
void output(Point &a){
    cout << "outer : " <<  a.x << ":" << a.y << endl; 
}
//返回值           //二元运算符<<   p 
ostream &operator<<(ostream &out,const Point  &p){
    // 和其余运算符一致，返回值的作用是给后面可能出现的值用的,因为一定返回的是ostream的引用
    // 也就是为了实现连续输出 
    out << " point (" << p.x <<  "," << p.y << ")";    
    return out;
}
//外部重载 
Point operator+(const Point &a ,const  Point &b){
    return Point (a.x +b.x , a.y + b.y );
}
ENDS(test);

BEGINS(test1)
int main(){
    test:: Point p(3, 4), q(5,6);
    p.output();
    output(p);
    //友元:类外的函数是无法访问类中私有成员属性,友元可以
    //  第二个值试图bind 左值引用形式,他是无法bind(p + q) 是临时匿名对象         
    // 为什么加上const参数,兼容所有对象的bind,也想兼容这种临时的匿名对象,兼容所有的参数类型
    cout << (p + (q + p )) << endl;
    cout <<  (q  +  q)  << endl;
    cout <<  (p + 5) << endl; 
    //const特殊类型
    const test::Point z(100,1000);
    cout << z + 6 <<endl;
    return 0;
}
ENDS(test1)


BEGINS(test2)
 int main(){
     test::Point p(3,4);
    // +=
    
     cout << (( p +=6 ) +=6) << endl;
    
     cout << (p++ ) <<endl;

     cout << (p) << endl;
    
     cout << ++p <<endl;
     return 0;
 }
ENDS(test2)


BEGINS(arrobj)
    //数组对象= 重载了[]运算符 如vector
    using namespace test;
    class arrary{
        public :
                arrary(int n = 100):n(n) ,data(new int[n]){}
                int &operator[](int ind){
                    return data[ind];
                }
                const  int &operator[](int ind) const{
                    return data[ind];
                }
       private :
                int n ;
                int *data;
    };


int main(){
    arrary arr;
    for(int i= 0; i < 10; i++){
        arr[i] = i ; //这里得是引用，不然会报错
    }

    for(int i= 0; i < 10; i++){    
        cout << arr[i] << "";
    }
    cout << endl;

    const arrary arr2;
    for(int i= 0; i < 10; i++){
        cout << &arr2[i] <<endl; //这里得是引用，不然会报错
    }

    for(int i = 0; i < 10; i++){
        cout << arr2[i] << ""; 
    }
    cout << endl;
    return 0;
}
ENDS(arrobj)

BEGINS(function_obj)
    //将类表现的像一个函数1
 class Function{
    public :
      int operator()(const int& a , const int& b)const {
            cout << " inner class :" <<" ";
            return a + b;
        }
    private:
 };

int func1(int a, int b){
    cout << " inner func1 " <<" ";
    return a + b ;
}

int main(){

    Function func;
    // cout <<   " call obj func " << func(3 , 4) << endl;

    //这个func 的本质是一个对象了 
    // c 语言这类函数指针表现形式为 传入两个int,类型是一定的，所以外在表现重要
    // //函数指针的本质就是在描述一个外在的表现，先声明后定义
    int (*p)(int , int)= func1;
    
    cout  << " p  pointer "  << p(3, 4) << endl;
    //Function *q =&func;
    //这没意义 并不是要吧类型bind 过来
  
    //function c++ 函数指针 对象
    //定义通用的函数指针，还可以指向函数对象
    //圆括号是 传入 尖括号是返回函数
    function<int(int,int)> q;
    //1: 吧普通的函数指针bind 过来
    q = func1;
    cout << " q pointer " << q(1 , 1) << endl;

    //2 : 把函数对象 bind 过来
    q = func;
    cout << " q obj pointer" << q(1 , 2) << endl;

    cout << greater<int>()(3, 4) << endl;
    return 0;
}

ENDS(function_obj)

BEGINS(pointer_obj)
struct A{
     int x , y ;
};
ostream &operator<<(ostream &out , const A &a){
     out <<  a.x << a.y <<endl;
    return out;
}
class Pointer{
public:
     Pointer(A *p = nullptr):p(p){}
     A *operator->(){return p;}
     A *operator->()const{return p;}
     A &operator*(){ return *p;}
     A &operator*()const  { return *p;}
     A *operator+(int n ){return p + n;}
     A *operator+(int n )const{return p + n;}
     A *operator-(int n ){return p - n;}
     A *operator-(int n )const{return p - n;}
     long  operator-(const Pointer &a){
         return this->p - a.p;
     } 
     A &operator[](int index ){return *(p + index);} 
     A &operator[](int index )const {return *(p + index);} 
     friend  ostream &operator<<(ostream & ,Pointer  &); 
private :
     A *p;
}; 
ostream &operator<<(ostream &out ,Pointer  &a){
    out << a.p;
    return out;
}

int main(){
    A a , b ;  
    Pointer p = &a , q =&b;
    cout << a <<endl;
    p-> x = 3;
    p-> y = 4;
    cout << a << endl;
    cout << *p <<endl;
    cout << p <<endl;
    cout <<(p + 1) << endl; 
    cout <<(p - 1 ) << endl;
    cout <<(p - q) << endl;

    return 0;
}
ENDS(pointer_obj)

int main(){
   // test1::main();
   //  arrobj::main();
   // function_obj:: main();
    pointer_obj :: main();
    return 0 ;
}
