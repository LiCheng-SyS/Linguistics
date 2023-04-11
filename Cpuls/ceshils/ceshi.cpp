#include <iostream>//头文件引用
using namespace std;//命名空间

//拷贝构造函数调用时机

class Person
{
public:
    Person()
    {
        cout << "Person默认构造函数调用" << endl;
    }
    Person(int age):m_Age(age) {
        cout << "Person有参构造函数调用" << endl;
       // m_Age = age;
    }
    Person(const Person& p1){
        cout  << "  拷贝构造"  << this  <<  &p1  <<    "Person拷贝构造函数调用" << endl;
     //  m_Age = p.m_Age;
    }
    ~Person()
    {
        cout << "Person析构函数调用" << endl;
    }
    int m_Age;
};

void test01()
{
   // Person p1 = 41;
//    Person p2(p1);
   // cout << "P2的年龄为：" << &p1 << endl;
}


int main(){//主函数{
   // test01();
    Person p1  = 45 ;
    cout << "p1 : "<< &p1 <<endl; 
    return 0;//返回到主程序
}
