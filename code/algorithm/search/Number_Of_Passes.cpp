#include<vector>
#include<iostream>
using namespace std;

// m 列 n为行
int n,m ,ans=1,sx,sy;//1开始走
int dir[4][2]={0,1,1,0,0,-1,-1,0};
char mmap[55][55];

int  rec;
void  writeline(){
    for(int i = 0; i <= 12; i++){
        for(int j=0; j< 13 ;j++){
            if(mmap[i][j]!='0') {
                cout << mmap[i][j] ;
            }
        }
        cout << endl;
    }
}

//循环是在计算新点坐标
void func(int x,int y){
    //循环四个方向
    for(int i = 0;i < 4;i++){
        int xx= x + dir[i][0];
        int yy= y + dir[i][1];
        // 以上为每次方向的新点坐标
        writeline();
        if(mmap[xx][yy] == '.'){
            ans++;
            mmap[xx][yy]= 0;        
            func(xx,yy);
        }
    }

}

int main(){
    //该题是先行在列  
    // m 列 n为行
    cin >> m >> n;    
    for(int i=1;i<=n;i++){
        for(int j = 1; j <=m;j++){
            //1，1 开始不需要判断边界
            cin >> mmap[i][j];
            if( mmap[i][j] == '@'){
                //@为起点
                sx=i,sy=j;
            }
        }
    }

    func(sx,sy);

    cout << ans <<endl;
    cout << rec <<endl;
    return 0;
}
