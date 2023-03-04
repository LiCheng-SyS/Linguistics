#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>

//二叉树的层级遍历  
using namespace std;

class Solution {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    void getRes(TreeNode* root,int k,vector<vector<int>> &ans){
        if(root == NULL) return ;
        if(k==(int)ans.size()) ans.push_back(vector<int>());
        ans[k].push_back(root->val);
        getRes(root->left,k+1,ans);
        getRes(root->right,k+1,ans);
        return ;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        getRes(root,0,ans);
        //头尾对调
        for(int i=0,j=ans.size()-1; i<j ;i++,j--){
            swap(ans[i],ans[j]);
        }
        return ans;
    }
};
int main(){

    return 0;
}
