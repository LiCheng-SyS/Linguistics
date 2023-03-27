#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
  
using namespace std;
  
int func(int x ){
    return 2 * x;
}

double func(double x){
    return 2.0 * x;
}

int ABS(int x ){
    return abs(x);
}
double ABS(double x){
    return fabs(x);
}
int main(){
    cout << func(1) << endl;
    cout << func(22.0) << endl;
    
    cout <<  ABS(222.56) << endl;
    cout << ABS(-233) << endl ;
  return 0;
}
