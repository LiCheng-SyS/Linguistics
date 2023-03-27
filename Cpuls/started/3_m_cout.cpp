#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#include<stdio.h>

#define  BEGINS(s) namespace s{
#define  ENDS(s)}

BEGINS(xx)
    const char endl = '\n' ;
    class istream {
    public : 
        istream &operator >>(int &x);
    };
    class ostream{
    public :
        ostream &operator << (int x);   
        ostream &operator >> (char ch);   
    };
ostream  cout ;
istream cin ; 
//& &operator返回的是这个的地址（引用）
//用处就在于这个运算符的连用性，如果需要连用的话必须使用引用。
//例如(a=b)=c，如果不返回引用的话像楼上说的那样
//，*this是当做临时变内量返回的容
//C++为了保证临时变量从产生到返回不被修改，从而把临时变量定义为const
//，因而(a=b)=c的话，a=b为一个const，c是不能赋值给他的。
ostream &ostream ::operator << (int x){
    printf("%d", x);
    return  *this;//返回对象的引用，为了连续赋值
}

ostream &ostream :: operator >> (char ch){
    printf("%c",ch);
    return *this;
}
istream &istream :: operator>> (int &x){
    scanf( "%d", &x);
    return *this;
}
ENDS(xx)


 int main(){
     int n , m ;
     xx::cin >> n  >> m;   
     xx::cout<< n  << m;
     return 0;
}
