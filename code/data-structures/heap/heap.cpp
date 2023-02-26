#include<vector>
#include<iostream>
#include<stdio.h>
using namespace std;


#define  MAX_N 1000
int data[MAX_N+5],cnt=0;


void output(int n){
    printf(" heap");
        for(int i=0;i<n;i++){
            printf(" %d",data[i]);
        }
        printf("\n");
        return;
}

int top(){
    return data[0];
}

void  shift_top(int ind){
    while(ind && data[(ind-1)/2]<data[ind]){
        swap(data[(ind-1)/2],data[ind]);
        ind =(ind -1) /2;  //再将index 变成父节点的坐标
    }
    return ; 
}

int size(){
    return cnt;
}

void push(int val){
    //首先放在末尾
    data[cnt++]=val; //insert add last
    /*  int ind =cnt;  //向上调整 子节点如何得到父节点的坐标  

    //->子节点-1 /2 就是父节点的坐标 (2i+1)-1/2 =i
    // 从0开始  左 位2i+1 ,右为2i+2  这是通过父确定子

    // 父节点小于子节点,则需要交换了
    while(ind && data[(ind-1)/2]<data[ind]){
    swap(data[(ind-1)/2],data[ind]);
    ind =(ind -1) /2;  //再将index 变成父节点的坐标
    }  //完成向上调整 */
    shift_top(cnt-1);
    return;
}


void pop(){
    if(size()==0)return;
    swap(data[0],data[cnt-1]);
    cnt-=1;
    //最大子节点的下标
    int ind=0,n=cnt-1;
    //判断index 有没有子节点
    while(ind * 2 + 1 <=n){
        int temp=ind;//ind ->三元组最大值的下标
        //如果最大值小于座子树,则 更新位左子树
        if(data[temp]< data[ind * 2 +1]) temp=(ind>>1)+1;
        //前面的条件可能为左子树 但可能没右子树 如果右才跑后面的代码 没有则不跑
        if(ind * 2 + 2 <=n && data[temp]< data[ind * 2 +2])temp= ind *2 +2;
        if(temp == ind)break;//说明三元组就是index的值
        //这里
        swap(data[temp],data[ind]);
        ind=temp; //继续向下调整
    }
    return ;
}

int main(){
    int op,val;
    int max_n=0;
    while(cin >> op){
        switch(op)
        {
        case 0 :{
                    cin >> val;printf("push %d to head\n",val);push(val);break;
                }break;
        case 1 :{
                     printf("pop%d from heap\n",top());pop();break;
                }break;
        case 2 :{
                    output(max_n);
                }break;
        }
        max_n=max(cnt,max_n);
        output(max_n);
    }
    return 0;
}
