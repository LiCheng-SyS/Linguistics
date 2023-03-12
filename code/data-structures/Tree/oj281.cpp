#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

using namespace std;
#define  BASE 26
typedef  struct Node{
    int  falg; //是否单独成词
    struct Node *next[BASE];
} Node ;

void clear(Node *);
Node *getNewNode();
void insert_Node(Node *,const char *); 

Node *getNewNode(){
    Node *p=(Node *)malloc(sizeof(Node));
    p->falg =0;
    memset(p->next,0,sizeof(Node *) * BASE);
    return p;
}

void insert_Node(Node *root,const char *str){
    Node *p=root;
    for(int i = 0; str[i]; i++){
        int ind =str[i] - 'a'; 
        //如果没有节点的则挂上节点
        if(p->next[ind]==NULL) p->next[ind] = getNewNode(); 
        //顺着相关节点的边 走向目标节点的相关位子
        p = p->next[ind];
    }
    //循环结束后,单词插入到字典树中
    p->falg += 1; //end 结束
    return;
}

int find(Node *root,const char *str){
    Node *p= root;
    int ans = 0; 
    for(int i =0; str[i];i++) {
        p = p->next[str[i] -'a'];
        if(p == NULL)return ans;
        ans += p->falg;
    }
    //实际上是查看是否单独成词
    return ans;
}

void clear(Node *root){
    if(root == NULL)return ;
    for(int i= 0; i <BASE; i++){
        clear(root->next[i]);
    }
    free(root);
    return;
}

//给字符串排序,将所有字符串都放入字典树，
//按DFS遍历，则为字符串排序 o(n) 代表单词总数
void output(Node *root, int k , char *buffer){
    if(root==NULL) return ;  
    buffer[k] = 0;
    //如果出现独立成词的状态输出
    if(root->falg) {
        printf("%s\n",buffer); 
    }
    for(int i = 0; i< BASE; i++){
        //当前字典树的第i的子孩子
        buffer[k] = 'a' + i; 
        output(root->next[i],k+1,buffer);
    }
    return;
}

char str[1000000];
int main(){
    Node *root= getNewNode();
    int n , m; 
    cin >>  n >> m;
    for(int i = 0; i < n; i++){
        cin >>  str ;
        insert_Node(root,str);
    }
    for(int i = 0; i < m; i++) {
        cin >> str; 
        cout  << find(root,str) << endl;    
    }
    clear(root);
    return 0;
}
