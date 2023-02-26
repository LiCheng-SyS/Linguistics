#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;


int n,m;//总的份数和期待切出来的份数

double num[10005],mmax; //长度，和最长的绳子

int func(double x){
   int cnt=0;
   for(int i=0;i<x;i++){
     cnt +=num[i]/x;
   }
   return cnt;
}


double bs(){
    double l=0,r=mmax;
    while(fabs(l-r)>0.0005){
        double mid=(l+r)/2;
        int s=func(mid); //总数多少根
        if(s>=m){
            l=mid;
        }else{
            r=mid;
        }
    }
    return r;
}

int main(){
    cin >> n>>m;
    for(int i=0;i<n;i++){
        cin>> num[10000];
        mmax=max(num[i],mmax);
    }
    double ans=bs();
    double t1 =int(ans * 100)/100.0;
    cout << t1 <<endl;
    return 0;
}
