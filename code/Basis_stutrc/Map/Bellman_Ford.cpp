#include <iostream>
#include<string>

using namespace std;

struct edge{
    int s ,e ,v; 
};

int n , m  ,ss , edg_index, ans[20005]; 
edge edg[20005];

void add_edg(int s1,int e1,int v1){
   edg[edg_index].s= s1;
   edg[edg_index].e= e1;
   edg[edg_index].v= v1;
   edg_index++;
}

int main(){
    int  f = 0;
    cin  >> n  >> m >>  ss;
    memset(ans,0x3f,sizeof(ans));
    for(int i =0 ; i < m ; i++){
        int  s1 , e1 ,v1;
        cin >> s1 >> e1 >> v1 ;

        add_edg(s1, e1, v1);
        add_edg(e1, s1, v1);
    }

     ans[s]=0;
     for(int i =0 ; i < n ; i++){
        // 由于是 双向边 ->要变更为edg_index
          for(int j =0 ; j < edg_index; j++){
            ans[edg[j].e]= min(ans[edg[j].e] ,ans[edg[j].s] + ans[edg[j].v] );
            //比较从s到u的距离与从s到v的距离加上w之和的大小，来更新从s到v的最短距离
            //     if (ans[edg[j].e] > (ans[edg[j].s] + ans[edg[j].v])) {
            //         ans[edg[j].e] = ans[edg[j].s] + ans[edg[j].v]
            //         f=1;
            //    }               
           }
        //    if(f==0){
        //      break;
        //    }
     }

     for (int i = 1; i <= n; i++)
     {
           if (ans[i] != 0x3f3f3f) {
                cout << ans[i] << endl;
           } else {
                cout << -1 << endl;
           }
     }
    return 0;
}