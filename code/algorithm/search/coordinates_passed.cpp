#include<vector>
#include<iostream>
#include<stack>

using namespace std;
//https://oj.haizeix.com/problem/405
// n 行  M 列 k 次数 temp 临时联通点
struct node{
    int x ;
    int y ;
};

int n,m,k,temp; 
int dir[4][2]={0,1,1,0,0,-1,-1,0};
char mmap[3005][3005];
int ans[3005][3005];
stack<node> sta;

void func(int x , int y){
    for(int i =1; i <=n; i++){
        int xx=x + dir[i][0];
        int yy=y + dir[i][1];
        //----------边界----------------------// ----去重--------
        if(xx < 1 || yy <1 || xx > n || yy > n || ans[xx][yy] !=0){
                                                   //访问过了则不允许重复访问
            continue;
        }
        if(mmap[x][y] != mmap[xx][yy]){
            temp++;
            // 相连的点+1
            ans[xx][yy]=1; //mask
            sta.push((node){xx,yy});

            //将答案求出
            func(xx,yy);
        }
    }
}

int main(){
    cin >>  n >> m  >> k;
    for(int i = 1; i <=n; i++)
    {
        cin >> mmap[i][1];
    }
    
    for(int i =1;i <=n; i++){
        for(int j= 1; j <= m; j++){
            if(ans[i][j] ==0){
                temp = 1;
                ans[i][j]=1;
                sta.push((node){i,j});
                func(i, j);
                //求解函数
                while(!sta.empty()){
                    //记录答案
                    node temp1 =sta.top();
                    sta.pop();
                    ans[temp1.x][temp1.y]=temp;
                }
            }
        }
    }

    for(int i =0 ; i < k; i++){
        int a ,b;
       // 输出答案
        cin >> a >> b; 
        cout << ans[a][b] << endl;
    }
    return 0;
}
