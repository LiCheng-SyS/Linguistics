#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#include<stdio.h> 
using namespace std;

// 暴力匹配字符串算法 
int brute_facre(const char *s , const char *t){
    for(int i =0 ; s[i]; i++) {
        int flag = 0 ;
        //  子串在模式串的文本对齐,寻找出是否可以匹配成功
        for(int j=0; t[j]; j++){
            // 模式串= j
            if(s[i + j] ==t[j]) { 
                cout << i + j << "-" << j << "yes" <<endl;
                continue; 
            }else{ 
                cout << i + j << " - " << j <<  " no " << endl;
                  flag = 1; 
                  break;     
            }
        }
        if(flag == 0) return i; 
    }
    return -1;
}

  
int main(){
 
    char  s[100],t[100];
    while(~scanf("%s%s",s,t)){
         cout << "find : " <<    t  <<  s   <<    brute_facre(s,t)  << endl;
    } 
    return   0;
}
