//DFS无向图
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 定义无向图的节点结构体
struct GraphNode {
    int val;  // 节点值
    vector<GraphNode*> neighbors;  // 节点的邻居节点
    GraphNode(int x) : val(x) {}
};

void DFS(GraphNode* node, vector<bool>& visited) {
    if (!node) return;
    visited[node->val] = true;
    cout << node->val << " ";
    for (auto neighbor : node->neighbors) {
        if (!visited[neighbor->val]) {
            DFS(neighbor, visited);
        }
    }
}

// 遍历无向图
void traverseGraph(GraphNode* node) {
    if (!node) return;
    int n = 0;
    vector<bool> visited(100, false); // 100 为节点数的最大值
    DFS(node, visited);
}

// 测试代码
int main() {
    GraphNode* node1 = new GraphNode(1);
    GraphNode* node2 = new GraphNode(2);
    GraphNode* node3 = new GraphNode(3);
    GraphNode* node4 = new GraphNode(4);
    node1->neighbors = {node2, node3};
    node2->neighbors = {node1, node4};
    node3->neighbors = {node1, node4};
    node4->neighbors = {node2, node3};
    traverseGraph(node1);
    return 0;
}