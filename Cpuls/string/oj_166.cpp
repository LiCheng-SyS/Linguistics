#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main(){
   string   a , b;
   int pos;
   cin >> a >> pos >> b ;
   
   cout <<  min(100,(int)a.size()) << endl;
   a.insert(pos-1,b);
   cout << a  << endl;

   int xx =  a.size() - (a.rfind("x"));
   cout <<  xx << endl;
   return 0;
}
