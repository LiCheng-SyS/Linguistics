#include<iostream>
#include<algorithm>
using namespace std;

int n,m,num[100005];
 int func(int x){   
   int t=1,last=num[0];
   cout   << "t:" <<  t <<"last: " <<last << endl; 
   for(int i=1;i<n;i++){
       if(num[i]-last>=x){
           t++;
           last=num[i];
       }
   }
   return t;
}

int bs(){
    int l =1,r=num[n-1]-num[0];
    while(l!=r){
      int mid=(l+r+1)/2;
      int s=func(mid);
      if(s>=m){
       l=mid;
      }else {
        r=mid-1;
      }
    }
  return l;
}


int main(){
    cin >>n >> m;
    for(int i=0;i<n; i++){
      cin >> num[i];
    }
    sort(num,num+n);

    cout <<bs()<< endl;
    return 0;
}
