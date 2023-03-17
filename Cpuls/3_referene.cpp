#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
  
using namespace std;

// &引用 整型的引用,这个实参才是修改的外部参数值,引用也不但占有存储空间
void add_one(int n){
    n +=1;
    return ;
}
int main(){
 
    int x1= 1 , b1=2;
    cout <<" normal_param "  <<endl;
    add_one(x1);
    add_one(b1);
    cout << x1 <<  " " << b1 << endl;
    return 0;
}
