#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include "tabtenn.h"   

using namespace std;
  
TableTennisPalayer::TableTennisPalayer(const string &fl ,const  string &ln, bool hs){
    firstname = fl; 
    lastname =ln;
    hastable = hs; 
}

void TableTennisPalayer::Name()const{
    cout << " lastname " <<  lastname  <<  " firstname " <<  firstname  ;
}
RatedPyaly::RatedPyaly(int r , const string &fn, const string &ln ,bool ht):
    TableTennisPalayer(fn,ln,ht)
{
    rating = r;
}

RatedPyaly::RatedPyaly(int r , const TableTennisPalayer &t) : 
    TableTennisPalayer(t),rating(r)
{

}

int main( void  ){
    //1 : 基类指针可以在不进行显示强转下指向派生类的对象，基类也可以引用可以在不进行显示强转的情况引用派生类的对象
  
    /*
    RatedPyaly ra1(1234,"M","cheng",true);
    TableTennisPalayer *tb2 =&ra1;
    TableTennisPalayer &tb3 = ra1;
    tb2->Name();
    tb3.Name();
    */
    //2不可以将基类对象的地址转为派生类的引用和指针；
    /*
    TableTennisPalayer table1("xxx","a1",true);
    不要作死,你如果倒着转, 那么 你这个意思就我把 派生类的地址 拽到了父类上,父类上是没有Rating属性的,这没意义
    RatedPyaly *py2 =&table1;
    RatedPyaly &py1 =table1;
    */

    //3:
    TableTennisPalayer t1("song x", "cheng",true); 
    TableTennisPalayer t2("song y", "cheng",false); 
    // 扩展  
    RatedPyaly ra(1234,"M","cheng",true);
    ra.Name();
    cout <<" : Rating :" <<ra.ratin() << endl;
    if(ra.HasTable()){
        cout << " RatedPyaly has table \n" ;
    }else{
        cout << " RatedPyaly hasn t a table  " ; 
    }

    t1.Name();
    if(t1.HasTable())
        cout << " has table \n" ;
    else
        cout << "hasn t a table  " ; 
    
    t2.Name(); 
    if(t2.HasTable())
        cout << " has table \n" ;
    else 
        cout << " has t table \n" ;

    return 0;
}
