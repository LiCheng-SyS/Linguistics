#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>

#define  SIZE 10

int sum(int *ar){
    int total = 0;
    for(int i=0;i< SIZE; i++)
    {
        printf("total -> %p   %p\n",*(ar+i),ar[i]);
        total += *(ar + i);
    }
    return total;
}


int  main(){
    int day[SIZE]={31,12,13,14,88,66,44,43,21,67};
    int xx =  sum(day);
    for(int i =0; i<SIZE;i++){
        printf(" %d\n",xx);
    }
    return 0;
}
