#include<vector>
#include<iostream>
#include<utility>
using namespace std;

int n ,m ;
int main(){
    //n个点 m条边
    cin >> n >> m ;
    //每个元素是一个vector ，表示一个顶点的邻居表
    //adj (call 构造器,第一个参数n 表adj的大小, 第二个参数每个vector都是一个空的pair<int,int>对象)
    vector<vector<pair<int,int > > > adj(n +1 ,vector<pair<int,int>>{});
    for(int i = 0 ; i < m ;i++) {
        int  s , e ,v ;    
        //s点  final 点  权值
        cin >> s >> e >> v;
        //在起点开始末尾插入 邻居的编号和边的权重。
        adj[s].push_back(make_pair(e,v));

    }
    //以这个点为起点并输出每个顶点的邻居列表的过程
    //为adj[i][0]是一个空的pair对象，用于占位，所以实际的邻居列表从adj[i][1]开始。
    for(int i = 1 ; i <= n;i++){
        cout << i <<" :  ";
        //编号 -->{邻居编号，边权重}， 例如{2,3}表示顶点i有一条边连接到顶点2，边权重为3。
        for(int j= 0 ;j < adj[i].size();j++){
            cout << "{" << adj[i][j].first << "," << adj[i][j].second << " }";
        }
        cout << endl;
    }


    return 0;
}
