#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include<time.h> 
using namespace std;

#define BEGINS(x) namespace x{
#define ENDS(x)} //namespace of  define 

BEGINS(test1)
class  Animal{
public : 
    void  run (){
        cout <<" how to  ainmo  run " << endl;
        return ;
    }
};

class Cat : public  Animal{
 public :
     void  run (){
         cout <<" run with four legs " <<  endl;
         return ;
     }
};

int main(){
    Cat a; 
    Animal *c = &a; 
    Animal &x = a ;
    //普通的成员方法是和类走的 调那个方法，需要看是那个类型
    a.run(); //cat go 
    c->run(); //aninmal go 
    x.run();  //animal go 
    return 0;
}

ENDS(test1)

BEGINS(test2)
//为了解决不合理的成员方法，C++的virtual 标记在普通的成员方法前 
//强调一下 父类中 某个成员方法是虚方法,子类中相同的成员方法 自动变为虚方法
class  Animal{
public : 
   virtual  void  run (){
        cout <<" how to  ainmo  run " <<endl;
        return ;
   }
};

class Cat : public  Animal{
 public :
     //由于父类中定义 run 方会出现普通成员方法的问题，所以需要标识overrider重写父类的run方法
     //标识覆盖父类 使得语义准确
    void  run() override {
         cout <<" run with four legs " <<  endl;
         return ;
     }
};

int main(){
    Cat a; 
    Animal *c = &a; 
    Animal &x = a ;
    // 成员方法  跟着类走 编译期的状态-> 没运行起来也有这个成本 
    // 虚函数 重写后跟着对象走  统一指向了cat对象 ，虚函数是在运行期的状态 
    //   
    a.run(); //cat go 
    c->run(); //aninmal go 
    x.run();  //animal go 
    return 0;
}

ENDS(test2)

BEGINS(test3)
//为了解决不合理的成员方法，C++的virtual 标记在普通的成员方法前 
//强调一下 父类中 某个成员方法是虚方法,子类中相同的成员方法 自动变为虚方法
class  Animal{
public : 
   virtual  void  run (){
        cout <<" how to  ainmo  run " <<endl;
        return ;
   }

   //当前基类标记virtual后 , 子类的析构也会自动标记析构
    virtual   ~Animal(){
       cout  << " Animal Destructor " << endl;
   }
};

class Cat : public  Animal{
 public :
     //由于父类中定义 run 方会出现普通成员方法的问题，所以需要标识overrider重写父类的run方法
     //标识覆盖父类 使得语义准确
    void  run() override {
         cout <<" run with four legs " <<  endl;
         return ;
     }
    ~Cat(){
        cout << "Bird destructor  " <<endl;
    }
};
class Pseron:public Animal{
    void run() override {
        cout <<" I can run With tow legs" << endl;
        return ;
    }
    ~Pseron(){
        cout <<"Pseron destructor "<<endl;
    }
}; 

class Bird : public Animal{
    void run() override {
        cout <<  "in can fly " <<endl;
        return;
    }
    ~Bird(){
        cout << "Bird destructor  " <<endl;
    }
};

int main(){
    srand(time(0));
    Animal * arr[10];
    for(int i =0 ; i < 10;i++){
        switch(rand() % 3 ){
            case 0 : arr[i] =new Cat();break;
            case 1 : arr[i] =new Bird(); break;
            case 2 : arr[i] =new Pseron(); break;
        }
    }
    for(int i =0 ; i < 10; i++){
        arr[i]->run(); 
    }
    return 0;
}
int main1(){
    //继承状态下无法正确析构子类的析构函数
    // 成员方法和类走 ，虚函数和对象走,delete 实际上是在调Animal的析构（析构也是成员方法 是和类一起的）
    srand(time(0));
    Animal * a;
    switch(rand() % 3){
        case 0 :  a =new Cat();break; 
        case 1 :  a =new Bird();break; 
        case 2 :  a =new Pseron();break; 
    }
    a->run();
    delete  a;//a 是通过类型来判断 ,是否析构
    return 0;       
}
ENDS(test3)

BEGINS(test4)
class  Animal{
public : 
    virtual  void  run () =0;

    virtual   ~Animal(){
       cout  << " Animal Destructor " << endl;
   }
};

class virtest:public  Animal{
public :
    void run() override{
        cout << "vir function " << endl;
    } 
};

class Cat : public  Animal{
 public :
     //由于父类中定义 run 方会出现普通成员方法的问题，所以需要标识overrider重写父类的run方法
     //标识覆盖父类 使得语义准确
    void  run() override {
         cout <<" run with four legs " <<  endl;
         return ;
     }
    ~Cat(){
        cout << "Bird destructor  " <<endl;
    }
};

class Pseron:public Animal{
    void run() override {
        cout <<" I can run With tow legs" << endl;
        return ;
    }
    ~Pseron(){
        cout <<"Pseron destructor "<<endl;
    }
}; 

class Bird : public Animal{
    void run() override {
        cout <<  "in can fly " <<endl;
        return;
    }
    ~Bird(){
        cout << "Bird destructor  " <<endl;
    }
};

int main(){
    //继承状态下无法正确析构子类的析构函数
    // 成员方法和类走 ，虚函数和对象走,delete 实际上是在调Animal的析构（析构也是成员方法 是和类一起的）
    srand(time(0));
    Animal * a;
    switch(rand() % 3){
        case 0 :  a =new Cat();break; 
        case 1 :  a =new Bird();break; 
        case 2 :  a =new Pseron();break; 
    }
    virtest xx;
    a->run();
    delete  a;//a 是通过类型来判断 ,是否析构
    return 0;       
}
ENDS(test4)


int main(){
   test3:: main1();
   return 0;
}
