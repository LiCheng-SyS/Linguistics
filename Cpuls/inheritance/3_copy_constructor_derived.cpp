#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>

//继承场景下 拷贝构造执行顺序  
using namespace std;  

#define  BEGIN(x) namespace x{
#define  ENDS(x)}   // namespace  of x 

BEGIN(test1)

    class ATTR_Base
{
public:
    ATTR_Base(string name) : name(name)
    {
        cout << name << endl;
    }
    ATTR_Base(const ATTR_Base  &base):name(base.name){
        cout <<" default copy attr  construct : " <<name << endl;
    }
    ~ATTR_Base(){
        cout << "ATTR  discharge construct " << endl;
    }

    ATTR_Base &operator=(const  ATTR_Base &a){
        name =  a.name ;
        cout << " ATTR_Base  operator =  :" << name  << endl;
        return *this ;
    }
    string name;
};

class ARRT_1 : ATTR_Base
{
public:
    ARRT_1(string name = "none ") : ATTR_Base(name) {}
};

class ARRT_2 : ATTR_Base
{
public:
    ARRT_2(string name = " none") : ATTR_Base(name) {}
};

class Base
{

public:
    Base() : arrt1("arrt1 in base"), arrt2("arrt2 in base") {
        cout << "Base Constructor do " << endl;
    }
    Base(const  Base &b):arrt1(b.arrt1),arrt2(b.arrt2){
        cout <<  " base copy  construct" << endl;
    }
    Base &operator=(const Base &b){
        cout << "Base  operator" <<endl;
        arrt1 = b.arrt1 ;
        arrt2 = b.arrt2 ;
        return *this; 
    } 
    ~Base(){
        cout  << " discharge construct  -> Base" << endl;
    }

private:
    ARRT_1 arrt1;
    ARRT_2 arrt2;
};

class derived : Base{
public:
    derived() : arrt1("atrr1 in devived "), arrt2("arrt2 in devived ")
    {
        cout << " derived   constructor  do " << endl;
    }

    derived(const derived &de):Base(de),arrt1(de.arrt1),arrt2(de.arrt2){
        cout <<  " copy derived done " << endl;
    }

    derived &operator=(const derived &de){
        this->Base::operator=(de);//default operator 来自于系统
        arrt1 = de.arrt1 ; 
        arrt2 = de.arrt2 ; 
        cout << " operator =node" <<endl;
        return *this;
    }
    ~derived(){
        cout << " free  derived" << endl;
    }
private:
    ARRT_1 arrt1;
    ARRT_1 arrt2;
};

int main(){
    cout << " default  construct ----------------" << endl;
    derived a ; 
    cout << "copy================= == construct" <<endl; 
    derived b (a);
    cout <<"operator assign ==============="  << endl;
    b = a ;
    return 0;
}
ENDS(test1)

int main(){
    test1::main();

    return 0;
}
