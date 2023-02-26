#include<vector>
#include<iostream>
#include<queue>
using namespace std;

//https://oj.haizeix.com/problem/527

struct node{
    int x , y ,step , d;
};
// -----------------------对于每个点来说，不同的能量应分开计算
int n ,m , d, mark [105][105][105];
int dir[4][2]= {0, 1 ,1, 0 ,0 , -1 , -1 ,0 };
char mmap[105][105];
int main(){

    // ------->>>>>>总计飞行距离
    cin >> n >> m >> d;
    for(int i=1 ; i<=n; i++){
        for(int j =1;j <=m ; j++){
            cin >> mmap[i][j];
        }
    }
    queue<node>  que;
    que.push((node){1,1,0,d});

    for(int i =0; i<=d ;i++){
        mark[1][1][i]=1;
    }
    while(!que.empty()){
        node temp = que.front();
        que.pop();
        //날 
        for(int i= 0 ; i< 4;i++){
            //要飞就不是指动一步
            for(int j = 2; j <=temp.d;j++ ){
                int x =dir[i][0] * j + temp.x;
                int y= dir[i][1] * j + temp.y;
                if(mmap[x][y]=='0'){
                    break;   
                }
                if(x==n &&  y==m ){
                    cout << temp.step + 1  <<endl;
                    // 검색한 해답  
                    return 0;
                }
                // 표기 
                //여기가   표기해서 만들지 않아
                if(mmap[x][y]=='P' && mark[x][y][temp.d -j]==0){
                    mark[x][y][temp.d - j]=1;
                    que.push((node){x,y,temp.step + 1, temp.d - j});
                }
            }
            //걷 
            int xx =dir[i][0] + temp.x;
            int yy =dir[i][1] + temp.y;

            if(xx==n && yy==m){
                cout << temp.step + 1 << endl;
                return 0;    
            }
            if(mmap[xx][yy]== 'P' && mark[xx][yy][temp.d]==0){   
                mark[xx][yy][temp.d]=1;
                que.push((node){xx,yy,temp.step + 1 ,temp.d});
            } 
        }
    }
    cout << "impossible" << endl;
    return 0;
}
