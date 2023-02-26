#include<vector>
#include<iostream>
#include<queue>

using namespace std;

struct node {
    int x, y ,step;
};

int n , m , sx ,sy ;
int dir[8][2]={1,2, 2,1 ,1,-2,-2,1,-1,2,2,-1,-1,-2,-2,-1};
int ans[405][405];
int main(){

    cin >> n >> m >> sx >> sy;
    ans[sx][sy]= -1;
    queue<node> que;
    que.push((node){sx,sy,0});

    while(!que.empty()){
        node temp =que.front();
        que.pop();
        for(int i =0; i< 8; i++){
            int xx= dir[i][0]+ temp.x;
            int yy= dir[i][1]+ temp.y;
            if(xx < 1 ||yy < 1 || xx > n || yy > m || ans[xx][yy]!=0){
                continue;
            }
            ans[xx][yy]=temp.step + 1;
            que.push((node){xx,yy,ans[xx][yy]});
        }
    }
    for(int i =1 ; i<=n;  i++){
        for(int j=1 ; j<=m; j++)
        {
            if(j !=1){
                cout << " ";
            }
            if(ans[i][j]==-1){
                cout << 0;
            }else if(ans[i][j]==0){
                cout << -1;
            }else{
                cout <<ans[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
