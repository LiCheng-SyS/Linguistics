#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>

#define  MAX_N 10000

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void quick_sort(int *num,int l,int r){
    while(l<r){
        int x=l,y=r,z=num[(l+r)>>1]; 
        do{
            while(num[x]<z)x++;
            while(num[y]>z)y--;
            if(x<=y){
                swap(num[x],num[y]);
                x++,y--;
            }
        }while(x<=y);

        quick_sort(num,l,y);
        l=x;
    }
    return ;
}

void output(int *arr,int n){
    for(int i=0;i<n;i++){
        i&& printf(" ");
        printf("%d",arr[i]);
    }
    return;
}

void initarr(int *arr,int n){
    for(int i=0;i<n;i++){
        arr[i]=n-i;
    }
    return ;
}


int main(){
    int arr[MAX_N]={0};
    initarr(arr,MAX_N);
    quick_sort(arr,0,MAX_N-1);
    output(arr,MAX_N);
    return 0;
}
