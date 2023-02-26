#include<vector>
#include<iostream>
#include<queue>

//https://oj.haizeix.com/training-ground/22/problem/399
//最少步数
using namespace std;
struct node{
    //-------步数
    int x ,y ,step;
};
//queue<node>  que;

// mapp size -- 起点位置 xy
int n ,m, sx , sy;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
char mmap[505][505];
int main(){
    cin >> n >> m; 
    for(int i=1 ; i <=n; i++){
        for(int j=1 ; j <=m; j++){
            cin >> mmap[i][j];
            if(mmap[i][j]=='2'){
                sx=i , sy=j;
            }
        }
    }
    queue<node>  que;
    que.push(node{sx,sy,0});
    while(!que.empty()){
        node temp =que.front();
        que.pop();
        for(int i =0 ; i < 4; i++){
            int xx=temp.x+dir[i][0];
            int yy=temp.y+dir[i][1];
            if(mmap[xx][yy] == '3'){
                cout <<temp.step +1  <<endl;
                return 0;
                //找到了终点
            }
            if(mmap[xx][yy]== '.'){
                mmap[xx][yy]=0; //可走路径,改0是为不重复搜索
                que.push((node){xx,yy,temp.step + 1 });
            }
        }
    }
    cout << -1 <<endl;
    return 0;
}
