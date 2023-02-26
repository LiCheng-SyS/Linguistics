#include<vector>
#include<iostream>
using namespace std;

int n;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int mmap[55][55];

void func(int x ,int y){
    for(int i=0;i < 4;i++){
        int xx=x + dir[i][0];
        int yy=y + dir[i][1];
        //  n为宽高 +1 必然越界
        //周围有0了需要判断边界了 
        if(xx < 0 || yy < 0 || xx > n + 1 || yy > n + 1){
            continue;
        }
        if(mmap[xx][yy]==0)  {
            mmap[xx][yy]=3;
            func(xx,yy);
        }
        //以上代码将所有边界值置为 3
    }
}

int main(){
    cin >> n; 
    for(int i=1; i<=n;i++){
        for(int j=1;j <=n ; j++){
            cin >> mmap[i][j];       
        }
    }
    //起点改成三

    mmap[0][0]=3;
    func(0,0);
    for(int i=1; i<=n;i++){
        for(int j=1;j <=n ; j++){
            if(j !=1 ){
             cout << "";
            }
        if(mmap[i][j] == 0){
            cout << 2;
        }else if(mmap[i][j]==1){
            cout << 1;
        }else{
            //==3
            cout << 0;
        } 
       }
        cout << endl;
    }
    return 0;
}
