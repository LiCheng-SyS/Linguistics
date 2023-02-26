#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
//-- 点 -边
int n, m, arr[105][105];

// Floyd算法计算每对顶点之间的最短路径。
int main()
{
    // 极大值 ,极大值加极大值不会越界
    memset(arr, 0x3F, sizeof(arr));
    // ---n点 --m个边
    cin >> n >> m;
    //  ----------------边
    for (int i = 1; i <=m; i++){
        int s, e, v;
        //----边---顶点--权值
        cin >> s >> e >> v;
        arr[s][e] = min(v, arr[s][e]);
         // 纵使有重边也会是最近的

    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (arr[i][j] != 0x3F3F3F3F) {
                cout << arr[i][j] << " ";
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

