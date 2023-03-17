#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>

using namespace std;

class A{
public:
    A(){
        cout << this  <<  "  default construct " << endl;
    } 
    A(int n, int m) :  n(n), m(m),
        arr(nullptr),size(nullptr),
        offset(nullptr) {
        cout << "A (int) construct" << endl;
    } 

    A(int *size ,int *offset):size(size) ,offset(offset){
        arr = new int[*size];
        arr += *offset; 
        cout <<"A *(int * size) construct " << endl;
    }
    ~A(){
        cout<< this  <<  "  destructor "  << endl;
        if(arr == nullptr) return ;
        arr -= *offset;
        delete  []arr;
    }
    int  *arr, *size, *offset, n , m; 
};
int main(){
    A a(3,4); 
    A b(&a.n,&a.m);
    cout << "&a " << &a << " &b" <<&b << endl; 
    return 0;
}
