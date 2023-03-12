#include <iostream>
#include <string.h>

using namespace std;

struct Edge{
    int to;     // 终点点
    int weight; // 权值
    int next;   //next 表示链表中下一条边的编号。z
};
Edge edg[100005];
int n, m, head[100005];  //表示所有边的列表。
//---点   边   链表

int main()
{
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        // s点  final 点  权值
        int s, e, v;
        cin >> s >> e >> v;
        // 无向图 你得遍历一趟，在回来一遍的你的数据 空间的需要x2
        edg[i].to = e;
        edg[i].weight = v;
        edg[i].next = head[s]; //同起点的最后一条边的num
        head[s] = i;//i =以该起点开始的最后一条边的编号
        //head[s] 则是表示该节点的头节点，head[s] 的值即为以 s 为起点的最后一条边的编号
        //将当前边的编号赋值给 head[s]，则可以更新以 s 为起点的最后一条边的编号，使其指向当前边。
    } //这样一来，以 s 为起点的边就会形成一条链，而链式前向星的优点就在于不需要事先知道图的边数，只需要不断向链中加入新的边即可。
    for (int i = 1; i <= n; i++){
        cout << i << ":";
        // 边的编号
        for (int j = head[i]; j != -1; j = edg[j].next)
        {
            cout << " {" << edg[j].to<< " ," << edg[j].weight << "}";
        }
        cout << endl;
    }

    return 0;
}
