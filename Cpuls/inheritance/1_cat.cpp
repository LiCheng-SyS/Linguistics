#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>

using namespace std;

#define BEGINS(x)namespace x{
#define ENDS(x)}

BEGINS(test1)
    class Base{
    public:
        int x; 
    protected:
        int y;
    private:
        int z;
    };

//----------------继承pubilc 父类
class public_base:public Base{
public  :
    void main(){
        x = y=2;
        //z=4; //private 不行
    }
};

class protected_base:protected Base {
public :
    void  output(){
        //   x = y = z =2;
        x = y = 2;
        //继承权限并不影响子类对父类的访问,但是影响外部访问子类继承自父类的属性  
        return ;
    }

};

class private_base: private Base{
public:
    void output(){
        //  x = y =z =2;
        x = y =2;
    }

};

int main(){
    /*  继承权限 
        public_base base_p;
        base_p.x = 1;
    // base_p.y = 4;  // base  protected 
    // base_p.z = 4; // base  private

    protected_base base_b;
    base_b.x= 1;// 由于是外部是外部在访问protected的继承权限就  protected + base - public == protected  
    base_b.y= 2;     
    private_base  pr_base ;
    pr_base.x=1;
    */
    return  0; 
}

ENDS(test1)

BEGINS(test2)
    class Base{
    public:
        Base(string  name):class_name(name){};
        int x ;
        string class_name;
    private : 
        int y ;
    };

class A : public Base {
public:
    A():Base("class A"){};
};
class B : public Base {
public:
    B():Base("class B"){};
};

class C : public Base {
public:
    C():Base("CLASS C"){};
};

void func(Base &a){
    cout  <<" in classname  :  " << a.class_name << endl;    
    return;
}
void func(Base *b)
{
    cout << " in  classmname"<<  b->class_name << endl ;
}
int main(){
    cout  << " Base Size" <<  sizeof(Base) <<  endl;
    cout  << " a Size " <<  sizeof(A) <<  endl;
    A a; 
    B b;
    C c;
    func(a); // func( &a ) 
    func(&a); // func(*a);
    return 0;
}



ENDS(test2)


BEGINS(test3)
class  ATTR_Base{
public :
ATTR_Base(string name) : name(name) {
    cout  <<  name  << endl;
}
~ATTR_Base(){
    cout << "attr_base  destruct  Base"  <<  endl;
}
 string name;
};

class ARRT_1 : ATTR_Base{
public :
    ARRT_1(string name):ATTR_Base(name){}
};

class ARRT_2: ATTR_Base{
public :
    ARRT_2(string name):ATTR_Base(name) { }
};

class Base{
public :
Base():arrt1("arrt1 in base") , arrt2("arrt2 in base"){
        cout << "Base Constructor do " << endl;
}
private: 
    ARRT_1  arrt1;
    ARRT_2  arrt2;
};

class  derived:Base{
public : 
    derived(): arrt1("atrr1 in devived "),arrt2("arrt2 in devived "){
          cout  <<" derived   constructor  do " <<endl;
    }
    ~derived(){
        cout <<" destruct  deviced " << endl;
    }
private: 
    ARRT_1  arrt1;
    ARRT_1  arrt2;
};

int main(){
    derived de;
    return  0;
}

ENDS(test3)

int main(){
    test3::main();
    return 0;
}
