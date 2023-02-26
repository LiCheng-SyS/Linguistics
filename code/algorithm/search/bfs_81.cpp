#include<iostream>
#include<queue>

using namespace std;

struct node{
    int x , y , step  , flag;
};

int n , m ,sx , sy , mark[2005][2005];
char mmap[2005][2005];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int main(){
    cin >> n >> m;
    for(int i = 1 ; i<= n;i++){
        for(int j =1; j <= m; j++){
            cin >> mmap[i][j];
            if(mmap[i][j]=='S'){
                sx=i , sy=j;
            }
        }
    }
    queue<node> que;
    que.push((node){sx,sy,0,0});
    mark[sx][sy] =1;
    while(!que.empty()){
        node temp =que.front();
        que.pop();
        for(int i = 0 ; i < 4 ;i++){
            int x =temp.x + dir[i][0];
            int y =temp.y + dir[i][1];
            //最终实现的条件
            if(mmap[x][y]=='T' &&  temp.flag==1 ){
                cout << temp.step + 1 << endl;
                return 0;
            }
            //---没有去买手机来过---------------------|| ->>>>>>>>>>>>>>>有手机来过了  ，来过就是重复搜
            if((temp.flag == 0 && (mark[x][y] & 1) !=0) || (temp.flag ==1 && (mark[x][y] & 2) != 0))  
            {
                continue;
            }
            //这都是没有拿到手机的情况
            if(mmap[x][y]=='S' || mmap[x][y]=='T' ||  mmap[x][y]=='.'){
                mark[x][y] +=  temp.flag + 1;
                //没手机的时候到==1 ，有手机来==2
                que.push((node){x,y,temp.step+1, temp.flag});
            }    
            //--拿到了手机
            if(mmap[x][y]=='P'){
                mark[x][y] =3 ;
                que.push((node){x,y,temp.step+1 ,1});
            }
        }
    }
    return 0;
}
