#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>




int bin_search(int *arr,int n,int val){
    int head =0,tail=n-1,mid=0;
    while(head<=tail){
        mid=(head+tail)>>1;
        if(arr[mid]==val)return mid;
        if(arr[mid]<val) head=mid+1;
        if(arr[mid]>val) tail=mid-1;
    }
    return -1;
}
//找第一个1

int binary_search1(int *arr,int n){
    int head=0,tail=n,mid;
    while(head < tail){
         mid=(head+tail)>>1;
         if(arr[mid]==1)tail=mid;
         else head=mid + 1;
    }
    return head==n? -1: head;
}


//找最后一个1 
int binary_search2(int *arr,int n){
    int head=-1,tail=n-1,mid;
    while(head< tail){//上取整
        mid =(head + tail+ 1)>>1;
        if(arr[mid]==1)head=mid;
        else tail =mid - 1;
    }
    return head;
} 



int main(){
    int arr[100]={0},n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    
    printf("%d\n",binary_search1(arr,n));
    return 0;
}
