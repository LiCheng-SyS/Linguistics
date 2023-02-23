#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <set>


using namespace std;
/*
所有商店到达仓库的距离和最小
从货仓到每家商店都要运送一车商品。
为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小，输出最短距离之和。

---------P----------
*/
int main(){
   vector<int> ans ;
   int n ,a ;
   cin  >>  n ; 
   for(int i =0 ;i < n; i++){
      cin >> a ; 
      ans.push_back(a);
   }
   sort(ans.begin(),ans.end());
   
   int mid =ans[n / 2] , sum;
   for(int i=0; i < n;i++) sum +=abs(ans[i]-mid);
   
   cout << sum <<endl;
   return 0;
}
