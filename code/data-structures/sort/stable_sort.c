#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<time.h>

#define TEST(arr,n,func,args...){\
    int * num=(int *)malloc(sizeof(int) *n);\
    memcpy(num,arr,sizeof(int) * n);\
    output(num,n);\
    printf("%s=",#func);\
    func(args);\
    output(num,n);\
    free(num);\
    printf("\n");\
}

//num --> arr copy

void output(int *num,int n){
    printf("[");
    for(int i=0;i<n;i++){
        i &&printf(" ");
        printf("%d",num[i]);
    }
    printf("]"),printf("\n"),printf("\n");
    return;
}



void swap(int &a,int  &b){
    // 选择排序除了问题自己异或了自己
   // a^=b;
   // b^=a;
   // a^=b;
   int temp=a;
   a=b ;
   b=temp;
    return;
}

// num位数组  val 为大小
void insert_sort(int *num,int n){
    for(int i=0;i<n;i++){
        for(int j=i;j>0;j--){
            if(num[j]<num[j-1]){
                swap(num[j],num[j-1]);
            }
        }
    }
    return;
}

void bubble_srot(int *num,int n){
    int times=1;
    for(int i=1;i<n&&times;i++){
        //第二层位从待排序区中开始逐个比较
        for(int j=0;j<n-i;j++){
            if(num[j]>num[j+1]){
                //当前大于后面的值则交换
                swap(num[j],num[j+1]);
                times=1;
            }
        }
    }
    return ;
}



//归并
void merge_sort(int *num,int l,int r){
    if(r-l<=1){
        if(r-r==1 && num[r]<num[l]){
            swap(num[r],num[l]);
        }
        return;
    }
    int mid=(l+r)>>1;
    merge_sort(num,l,mid);
    merge_sort(num,mid+1,r);
    int *temp=(int *)malloc(sizeof(int) *(r-l+1));
    int p1=l,p2=mid+1,k=0;
    while(p1<=mid || p2<=r){
        //先放置哪一块
        //第二段数组没元素了 或第一段有元素
        if(p2>r ||( p1<=mid && num[p1]<=num[p2])){
            temp[k++]=num[p1++];
        }else{
            temp[k++]=num[p2++];
        }
    }
    //从num+l的地址向后拷贝
    memcpy(num+l,temp,sizeof(int) *(r-l+1));
    free(temp);
    return;
}


void select_sort(int *num,int n){
    for(int i=0; i<n;i++){
        int inx=i;
        for(int j=i+1;j<n;j++){
            if(num[j]< num[inx]){
                inx=j;
            }
        }
        swap(num[inx],num[i]);
    }
    return;
}

void quick_sort(int *num,int l,int r){
    if(l>r)return;
    int x=l,y=r,z=num[x];
    while(x<y){
        while(x < y &&num[y]>z)y--;
        if(x<y)num[x++]=num[y];
        while(x<y &&num[x] <z )x++;
        if(x<y)num[y--]=num[x];
    }   
    num[x]=z;
    quick_sort(num,l,x-1);
    quick_sort(num,x+1,r);
    return ;
}


void randint(int *num,int n){
    while(n--)num[n]=rand()%100;
    return;
}

int main(){
    srand(time(0));
#define MAX_N 20
    int arr[MAX_N];
    randint(arr,MAX_N);
    TEST(arr,MAX_N,insert_sort,num,MAX_N);
    TEST(arr,MAX_N,bubble_srot,num,MAX_N);
    TEST(arr,MAX_N,select_sort,num,MAX_N);
    TEST(arr,MAX_N,merge_sort,num,0,MAX_N-1);
    TEST(arr,MAX_N,quick_sort,num,0,MAX_N-1);
#undef MAX_N
    return 0;
}
