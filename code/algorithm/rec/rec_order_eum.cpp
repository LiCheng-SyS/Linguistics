#include<vector>
#include<iostream>
using namespace std;

//n=范围
int n,num[15],mark[15],deep=1;
//全排列
void print(){
    for(int i =1; i <=n ; i++){
        if(i !=1 ){
            cout << " ";
        } 
        cout << num[i];
    }
    cout << endl;
}

void func(){
    if(deep == n+1){
        print();
        return;
    }
    for(int i =1 ;i <=n; i++){
        //先到n为止
        if(mark[i]==0){
            num[deep]=i;
            mark[i]=1;
            deep++;
            func();
            deep--;
            mark[i]=0;
        }
    }
}
int main(){
    cin >> n;
    func();
    return 0;
}
