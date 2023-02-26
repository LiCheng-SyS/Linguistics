#include<iostream>
using namespace std;


int n , m ,target,num[1000000],mark[1000005];

int main(){
    //6 15
    //1 7 21 8 16
    cin >>n>>target;
    for(int i=1;i<=n;i++){
       cin >> num[i];
       cout <<num[i] <<endl;
       mark[num[i]]=i;//这里是存的是下标
       cout << "mark[]"  << i<< " " <<mark[i]  << endl;
       // 每来进来都存,如果mark存在t  mark 存在的数组的下标
    }
    for(int i=1;i<=n;i++){
       
        cout << " 第二ceng层" << num[i] <<target<<endl;
        int t =target-num[i]; //每次应该的数字
        if(mark[t]!=0){
            // 从1开始跑的循环 所以-1 
            cout << "i" <<mark[t] <<endl;
            cout << i-1 << mark[t]-1 << endl;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}
