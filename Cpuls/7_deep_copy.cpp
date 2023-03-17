#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
#define  BEGINS(x) namespace x {//begin of namespace 
#define  ENDS(x)} //end of namespace x 

BEGINS(xxx)
class A {
    public :
        int x , y;
};

ostream &operator<<(ostream &out ,const A &a){
    out <<  "(" << a.x <<   " , " << a.y << ")";
    return out; 
}
//模板
template<typename T>
class Vector{
public:
    // to do 并未解决第一次构造 并未解决 初始化数组调用多次构造函数的问题 
    //如果没有传默认的构造器，会直接报错.所以。可以考虑直接申请内存空间
    // Vector(int n = 100):n(n),data((T *)calloc(sizeof(T), n)){}
    Vector(int n =100) : n(n),data(new T[n]){}
    Vector(const Vector &a):n(a.n){
        //  data = new T[n];//实现深拷贝， 带new 就调用n次构造函数
         data =(T *)malloc(sizeof(T) * n);
        /* for(int i = 0; i < n; i++){
           data[i]=a.data[i];
           } */
        //1 : memcpy 可能是复制类型是复杂类型的对象
        //原位构造 new (地址),其意思为:在某个地址上调用某个构造函数,构造一个相关的对象
        for(int i = 0; i < n; i++){
            //如果数据类型T执行深拷贝的函数,将call T类型的拷贝构造函数 
            new (data + i) T(a.data[i]); //这里也调了i次
        }
      // memcpy(data,a.data,sizeof(T) * n);
        return ;
    }
    T &at(int ind){
        cout << "ind" << ind << endl;
        return data[ind];
    }
    T &operator[](int ind) {return data[ind];}
    void output (int m = -1){
        if(m == -1) m = n;    
        cout << "Arr size " << " "<<  this << " : ";
        for(int i = 0; i < m; i++){
            cout << data[i] << " ";
        }
        cout << endl;
        return ;
    }
private : 
    int n ;
    T *data;
};
ENDS(xxx)

BEGINS(test1)
    using namespace xxx; 
    int main(){
        Vector<int>  arr;
        for(int i=0; i< 10; i++) arr[i]=i;
        arr.output(10);
        Vector<int>  arr2(arr);
        arr2.output(10);
        arr2[3]=1000;
        arr.output(10);
        arr2.output(10);
        return   0;
    }
ENDS(test1)


BEGINS(test2)
    using namespace xxx;

    int main(){
        Vector<A> arr1;
        for(int i =  0; i < 10; i++){
            arr1[i].x = i;
            arr1[i].y = 2 * i;
        }
        arr1.output(10);
        Vector<A> arr2(arr1);
        arr2[3] = (A){4, 100};
        arr2.output(10);
        arr1.output(10);
        return 0;
    }
ENDS(test2)

BEGINS(test3)
    using namespace xxx;

    int main(){
        Vector<Vector<int>> arr1;
        Vector<Vector<int>> arr2(arr1);

        arr2[2][2]=1000;
        for(int i =0; i < 3 ; i++){
            arr1[i].output(3);
        }
        for(int i =0; i < 3 ; i++){
            arr2[i].output(3);
        }
        return 0;
    }
ENDS(test3)


    int main(){
        //   test1::main();
       // test2::main();
        test3::main();
        return 0;
    }
