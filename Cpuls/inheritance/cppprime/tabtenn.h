#ifndef __tabtenn_H__
#define __tabtenn_H__
#include <string>

using std::string ; 
class TableTennisPalayer{
public:  
    TableTennisPalayer(const string &fn = "none" , const string &ln="node" , bool ht= false);
    void Name()const;
    bool HasTable()const{return hastable; }
    void RestTable(bool b){hastable = b;}
 private :
    string firstname; 
    string lastname;
    bool hastable; 
};
//头文件只定义
//派生类继承了基类的实现
//派生类继承了基类的接口
class RatedPyaly : public TableTennisPalayer {
// 派生类需要自己的构造器 
//派生类根据额外添加数据成员 和成员函数
//2 : 派生类无法访问父类private 修饰的方法和成员 ，如果想要访问私有成员，请显示写出方法

//派生类需要自己的构造函数 ,也可以添加额外的成员和成员函数
//在派生类创建对象时,首先init 父类 构造函数 , 释放 先从子类开始释放
private : 
    int rating ; 
public  :  
   //  RatedPyaly(int r ,const string &fn  , const string &ln , bool ht );
     //如果没有显示的初始化列表 ，则会调基类默认的构造函数 
     RatedPyaly(int r ,const TableTennisPalayer &tp);
     //当前拷贝构造函数，如果没显示的写出，编译器会使用默认的拷贝构造     
     RatedPyaly( int r=0 , const string &fn = "none" , const string &ln="node" , bool ht= false);
    // RatedPyaly(int r=1  , const TableTennisPalayer& tp );
     int   ratin()const {return rating;}
     void RatedRating(int r) {rating = r;}
};
// 只要不显示的声明构造函数,系统将使用默认的构造的函数,在使用的显示的构造函数时 必须要显示实现属性
// 如果子类做了显示的拷贝构造，必须要显示的调基类的构造器 ，不然后果很严重（因为父类执行默认构造）
// 导致默认的构造拷贝行为出现了问题

 #endif

