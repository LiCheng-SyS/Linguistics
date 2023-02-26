#include<vector>
#include<iostream>
using namespace std;

//组合型问题
int n , m, num[15] , deep=1;

void print(){
    for(int i=1;i <=m ;i++){
        if(i !=1){
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}
//len 还剩多少书需要选
void  func(int s,int len){
    if(len==0){
        print();
        //如果为0 就是选完了。
        return ;
    }
    //从s开始选
    for(int i=s;i<=n;i++){
         num[deep]=i;//选的数
         deep++;
         func(i + 1,len -1 );
         deep--;
    }
}

int main(){
    cin >> n >> m;
    //还剩下多少个数要选
    func(1,m); 

    return 0;
}
