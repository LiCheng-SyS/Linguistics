#include<iostream>
using namespace std;


int num[30][30] ,ans;
int dirx[4]={-1,0,1,1};/*定义方向数组*/
int diry[4]={1,1,1,0};

int main(){
    for(int i=5;i<25;i++){
        for(int j=5;j<25;j++){
            cin >> num[i][j];
        }
    }

    for(int i=1;i<25;i++){  //x 行
      for(int j=1;j<25;j++){  // y 列
          for(int k=0;k<4;k++){  //方向
              int t=num[i][j];
              for(int l=1;l<4;l++){ //除了自己的走三步数
                    //新坐标
                    int x= i+l * dirx[k];     //当L=1  l的倍数去乘对应方向格子
                    int y= j+l * diry[k]; //l倍的纵坐标
                    t *=num[x][y];
                   cout<< x <<endl;
                   cout<< y <<endl;
              }
              ans=max(ans,t);
          }
       }
    }

    cout<< ans <<endl;
    return 0;
}
