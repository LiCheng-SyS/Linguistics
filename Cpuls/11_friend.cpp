#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Point{
public:
    Point(int x , int y):x(x),y(y){}
    void output(){
        cout << "inner " << " x" << x  << " y" << y <<endl;  
        return ;
    }
    friend void output(Point &);
    friend ostream &operator<<(ostream &,const Point &);
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

int main()
{
    Point p(3, 4);
    p.output();
    output(p);
    //友元:类外的函数是无法访问类中私有成员属性,友元可以
    return 0;
}

