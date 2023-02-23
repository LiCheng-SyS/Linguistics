//单源最短路 
//只能有一个起点，图中无负权边。
//        1
//     /     \
//    / -1    \
//   2 ------- 3
//      2
// 如果我们要从顶点1出发
// 通过最短路径算法计算到达顶点2的最短路径
// 则通过Dijkstra算法
// Bellman-Ford算法都会认为从1->3->2是最短路径
// 其路径长度为1，但实际上通过1->2的路径长度为-1，
// 比路径1->3->2更短。
#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

struct node
{   // 当前点，到达的权值多少  大顶堆
    int now,val;
    bool operator< (const node &b) const {
        return this->val > b.val;
    }
};

struct edge{
    int e , v ,next; 
};

edge edgp[200005];
int n , m , s, edgp_index ,head[100005],ans[100005];


//链式前向星
void add_edg(int ss ,int  e, int  v ){
    edgp[edgp_index].e=ss;
    edgp[edgp_index].v=v;

    edgp[edgp_index].next= head[ss];
    head[ss]=edgp_index;
    edgp_index++;
}


int main(){
    memset(head, -1 , sizeof(head));
    memset(ans ,0x3f,sizeof(ans));  
    cin  >> n >> m >> s;

    for(int i = 0; i < m; i++){
        int ss , e, v;
        cin >> ss >> e >> v ; 
        //则在代码实现时将无向图转换为有向图，
        //比如将一条无向边(u, v)    -------------------<存边
        // 转化为有向边(u, v)和有向边(v, u)两条，
        //一去一回
        add_edg(ss , e, v );
        add_edg(e, ss , v );  
    }
    //默认为极大值
    priority_queue<node> que;
    que.push((node){s,0}); /// ==>准备
    ans[s]=0;
    while (!que.empty()){
        node temp = que.top();
        //队顶元素                 
        //状态对应的权值 不等于这点对应的答案，表示这个点已经存储过了
        if(temp.val != ans[temp.now]){
            continue;
        }
               //----   所对应最后一条边的编号
        for(int i = head[temp.now]; i!=-1;i=edgp[i].next){
            int e = edgp[i].e , v= edgp[i].v;
            //edgp终点  ---           权值
            if(ans[e] > (temp.val + v)){
            //----------上一个点的权值 + 这条边的权值
                ans[e] = temp.val + v;

                que.push((node){e,ans[e]});
            } 
        }
    }
    for (int i = 0; i < n; i++)
    {
       if(ans[i] != 0x3f3f3f){
         cout << ans[i]<< endl;
       }else{
         cout << -1 <<endl;
       }
    }
    
   return 0;
}