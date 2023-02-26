#include<vector>
#include<iostream>
#include<queue> 
using namespace std;

struct  node{
    int now ,step;  
};

int n ,s ,e ,mark[200],num[200];
int main(){

    cin >> n >>s >> e;

    for(int i =1; i <=n ;i++) {
        cin >> num[i];
    }
    queue<node> que;
    que.push((node){s,0});
    mark[s]=1;

    while(!que.empty()){
        node temp =que.front();
        que.pop();
        if(temp.now == e){
            cout <<temp.step <<endl;
            return 0;
        }

        int up=  temp.now + num[temp.now];    
        cout  << up <<endl;
        int down =temp.now - num[temp.now];
        cout << down <<endl;
        if(up <= n && mark[up]==0){
            mark[up]=1;
            que.push((node){up,temp.step+1});
        }
        if(down >=1 && mark[down]==0){
            mark[down]=1;
            que.push((node){down,temp.step +1});
        }
    }
    cout << -1 << endl;
    return 0;
}
