#include<vector>
#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;


int cacl(char *s,int l, int r){
    int op=-1,pri=10000-1,cur_pri,temp=0;   //cur_pri=运算符的优先级， 额外的由括号增加的优先级 
    for(int i=l;i<=r;i++){
        cur_pri=10000;
        switch(s[i])
        {
        case '+':
        case '-':cur_pri =1+temp;break;
        case '*':
        case '/':cur_pri =2+temp;break;
        case '(': temp+=100;break;
        case ')':temp-=100;break;
        }
        if(cur_pri <= pri){
            //当前的优先级 <记录的优先级的话
            pri=cur_pri;
            op=i;
            //找到整个表达优先级最低的位置
        }
    }
    if(op==-1){
        // 位置没运算符  ，纯数字
        int num =0;
        for(int i=l;i<=r;i++){
            if(s[i]<'0'||s[i]>'9')continue;
            num=num * 10 +(s[i] - '0');//转数字
        }
        return num;
    }
    cout << "find ：" <<s[op] <<endl;
    //递归计算两侧数据
    int a=cacl(s,l,op-1);
    int b=cacl(s,op+1,r);


    switch(s[op])
    {
    case '+':return a+b;
    case '-':return a-b;
    case '*':return a*b;
    case '/':return a/b;
    }
    return 0 ;
}


int main(){
    char s[100];
    while(~scanf("%[^\n]s",s)){
        getchar();
        printf("%s = %d\n",s,cacl(s,0,strlen(s)-1));
    }
    return 0;
}
