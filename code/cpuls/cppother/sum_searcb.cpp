#include<iostream>
using namespace std;




int target,n,num[1000000];
int main(){
     cin >> n >> target;  
     for(int i=0;i<n;i++){
       cin >> num[i];  
    }
    int l=1,r=n-1;
    while(l<r){
        int t= num[l]+num[r];
        if(t==target){
          cout << l << r <<endl;
         return 0;
        }else if(t>target) {
            r--;
        }else{
            l++;
        }
    }

    cout << "no" <<endl;
    return 0;
}
