#include<vector>
#include<iostream>
using namespace std;

int n ,m, ans;
int dir[4][2] = {0,1,1,0,0,-1,-1,0};
int mmap[55][55];

void func(int x, int y){
    for(int i =0; i < 4; i++){
        int xx=x + dir[i][0];
        int yy=y + dir[i][1];
        if(mmap[xx][yy]!=0){
            //计算了新起点 同样置为0 ,然后计算新的坐标上右下左,如果到边界则回溯
            mmap[xx][yy]=0;
            func(xx,yy);
        }
    }
}
int main(){
    //n = 行 m=列
    cin >> n >> m; 
    for(int i = 1; i<=n ; i++){
        for(int j=1 ; j<=m; j++){
            cin >> mmap[i][j];      
        }
    }
    for(int i = 1; i<=n ; i++){
        for(int j=1 ; j<=m; j++){
            if(mmap[i][j]!=0){
                //这里一定是需要统计的数量
                ans ++;
                //计算起点
                mmap[i][j]=0;
                func(i,j);
            }
        }
    }
    cout << ans <<endl;
    return 0;
}


