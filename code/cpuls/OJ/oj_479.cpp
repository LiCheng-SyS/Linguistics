#include<iostream>
#include <cmath>
using namespace std;


int s11[10000][2],s21[5000][2],cnt11,cnt21;

void print(){
    for(int i =0; i<=cnt11;i++){
        cout <<s11[i][0]<< ": "<<s11[i][1]<<endl;
    }
    cout <<endl;
    for(int i=0;i<=cnt21;i++){
        cout <<s21[i][0]<<" : "<<s21[i][1]<<endl;
    }
}

int main(){
    char s[30];
    while(cin >> s){
        for(int i=0;s[i];i++){
            if(s[i]=='E'){
                print();
                return 0;
            }

            //=这里就是加分
            if(s[i]=='W'){
                s11[cnt11][0]++;
                s21[cnt21][0]++;
            }else{
                s11[cnt11][1]++;
                s21[cnt21][1]++;
            }
            //判断是否结束  第1 个人分数>=11  必须是两人的之间有一个人分数>=11 因为这样才能结束
            //或者两个人的分差是有两分或者大于2分
            if((s11[cnt11][0]>=11|| s11[cnt11][1]>=11) && abs(s11[cnt11][0]-s11[cnt11][1]) >=2){
                  cnt11++;
            }
            //上面是判断11分下是否结束
            
            //下面是判断21分下是否结束
            if((s21[cnt21][0]>=21 || s21[cnt21][1]>=21) && abs(s21[cnt21][0]-s21[cnt21][1])>=2){
                    cnt21++;
            }

        }
    }

    return 0;
}
