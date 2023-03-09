#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>

//层级遍历
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int levelOrder(TreeNode* root)
{
    unsigned long ans=1;  //long会爆
    queue<pair<TreeNode*,unsigned long>>q;
    q.push({root,1});
    while(!q.empty())
    {
        unsigned long l,r,sz=q.size();
        for(int i=0;i<sz;i++)
        {
            auto [cur,id]=q.front();q.pop();
            if(cur->left) q.push({cur->left,id*2});
            if(cur->right) q.push({cur->right,id*2+1});
        }
        if(q.size()){
            l=q.front().second; r=q.back().second;
            ans=max(ans,r-l+1);
        }
    }
    return ans;
}
int widthOfBinaryTree(TreeNode* root) {
    return levelOrder(root);
}  

int main(){


    return   0;
}
