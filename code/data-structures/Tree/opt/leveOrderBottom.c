#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
//层级遍历
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int getHeight (struct TreeNode* root){
    if(root ==NULL) return 0;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    return (l > r ? l : r) + 1 ;
}

void getColSize(struct TreeNode* root,int k ,int *colSize){
    if(root==NULL) return ;
    colSize[k] += 1;
    getColSize(root->left , k+1,colSize);
    getColSize(root->right ,k+1,colSize);
    return ;
}

void getres(struct TreeNode* root,int k, int *colSize,int **ret){
    if(root==NULL) return ;
    ret[k][colSize[k]++] = root->val;
    getres(root->left,k+1,colSize,ret);
    getres(root->right,k+1,colSize,ret);
    return;
}
#define swap(a,b){\
    __typeof(a) c= a;\
    a = b , b = c ; \
}
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    //先得到树高 也就是深度
    int k = getHeight(root);
    int **ret= (int **)malloc(sizeof(int *) * k);
    //每一行需要几列-->每层元素的数量
    int *colSize= (int *)malloc(sizeof(int) * k);
    memset(colSize,0,sizeof(int) * k);

    getColSize(root,0 ,colSize);
    for(int i = 0 ; i< k ;i++ ){
        //  printf("%d",colSize[i]);
        ret[i] = (int *)malloc(sizeof(int) * colSize[i]);
        colSize[i]=0;
        //相应行的标记位
    }
    getres(root , 0 ,colSize ,ret);
    printf("\n");
    *returnSize = k ;
    *returnColumnSizes=colSize;
    for(int i = 0 , j = k-1; i< j; i++,j--){
        swap(colSize[i],colSize[j]);
        swap(ret[i],ret[j]);
    }
    return ret;
}

int main(){

    return 0;
}
