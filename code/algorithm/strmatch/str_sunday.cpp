#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<algorithm>
#include<stdio.h> 
#include<string.h>

using namespace std;

#define TEST(func, s ,t){\
    printf(" %s (%s , %s) =%d\n", #func,s,t,func(s,t));\
}
char  s[100],t[100];
int nxt[100];
//力匹配字符串算法 KMP
int brute_force(const char *s , const char *t){
    for(int i =0 ; s[i]; i++) {
        int flag = 0 ;
        //  子串在模式串的文本对齐,寻找出是否可以匹配成功
        for(int j=0; t[j]; j++){
            // 模式串= j
            if(s[i + j] ==t[j]) { 
                // cout << i + j << "-" << j << "yes" <<endl;
                continue; 
            }else{ 
                //cout << i + j << " - " << j <<  " no " << endl;
                flag = 1; 
                break;     
            }
        }
        if(flag == 0) return i; 
    }
    return -1;
}

int getNext(char ch, int j, const char *t){
    while(j != -1 && t[j +1 !=ch]) j = nxt[j];
    if(t[j + 1] == ch ) j += 1;
    return j;
}

int kmp(const char *s ,const char *t){
    nxt[0] = -1;  // 控制边界条件
    //  -1 ==把模式串vim 一个位置，next数组的第一位是模式串的第一位
    //  即使计算next 1 的时候  起始是  0 + 1 的位子在比较
    //  如果 下标为 0  和 0 + 1 的位置则存0的 位置  否则为-1 
    //，如果发现当前s[i]和t[j+1]不匹配
    //，就利用nxt数组回溯到t[j+1]之前的位置
    //，然后继续匹配。如果匹配成功，就将j向后移动一位。如果t[j+1] == 0
    //，说明t已经匹配完成了，此时返回匹配的起始位置i-j。
    //init 
    for(int i = 1,j = -1 ; t[i];i++){
      //  nxt[i] = (j = getNext(t[i],j,t));
       while(j != -1  &&  t[j + 1] != t[i]){      
            j = nxt[j];  
            cout << "nxt[x]" << nxt[j]<< endl;
        }
        if(t[j + 1 ] == t[i] ) j += 1;
        nxt[i] = j ;
    }
    //use 
    //i位置之前 匹配成功的模式串的那一位 
    for(int i =0,j = -1 ; s[i]; i++){
       // j = getNext(s[i] , j ,t);
       // if(t[j + 1 ]==0 ) return i - j; 
     while( j != -1 && s[i] != t[j + 1] ) j =nxt[j];
        if(s[i]== t[j + 1] ) j += 1 ;
        if(t[j +1 ] == 0)return  i - j ;
    }

    return -1;
}

int sunday(const char *s , const char *t){
    int len_t = strlen(t),len_s =strlen(s);
    //需要一个数组来记录 母串最后出现的位子     
    int ind[256]; 
    for(int i =0 ; i <256 ; i++) ind[i]= len_t +1;
    for(int i = 0 ; t[i]; i++){
        ind[t[i]] = len_t - i ;
    }
    
    //文本串的第i位
    int i = 0; 
    while(i + len_t <= len_s ){
        int flag = 1;
        for(int j =0 ;t[j]; j++){
            if(s[i + j] ==t[j])continue;
            flag= 0;
            break;
        }
        if(flag == 1)return i;
        i +=ind[s[i + len_t]];
    }
    return -1;
}

int main(){
    // while(~scanf("%s%s",s,t)){
    char s[] = "BBC ABCDAB ABCDABCDABDE";
    char t[] = "ABCDABD";
    TEST(brute_force,s ,t);
    TEST(kmp,s,t);
    TEST(sunday,s,t);
    //} 
    return   0;
}

