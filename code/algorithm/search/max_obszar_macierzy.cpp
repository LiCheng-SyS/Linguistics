#include<vector>
#include<iostream>
using namespace std;

// 536 最大黑色区域
int  n , m ,ans,temp;
int dir[4][2] ={0,1,1,0,0,-1,-1,0};
char  mmap[55][55];

void func(int x,int y){
    for(int i=0 ;i < 4 ; i++){
        int xx=x + dir[i][0];
        int yy=y + dir[i][1];
        if(mmap[xx][yy]=='1'){
            temp++;
            mmap[xx][yy]=0;
            func(xx,yy);
        }
    }
}

int main(){
    //n = 行 m =列
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j  =1; j<=m ;j++){
            cin >> mmap[i][j];
        }
    }
    for(int i =1; i<= n;i++){
        for(int j =1; j<=m ;j++){
            if(mmap[i][j]=='1'){
                temp =1;
                mmap[i][j]=0;

                func(i,j);
                ans=max(ans,temp);
            }
        }
    }

    cout << ans << endl ;
    return 0;
}
