#include<iostream>
using namespace std;


struct node{
    char s[4];//接受输入的数组
    int num1,num2,flag;
    //他可能有两个球,分别 第一球  第二球的分数，这句有没有触发加分机制  2为一击全中  0位不加分 
};

//s是比赛情况  num1 第一球得分, num2 两球总分 flag 加分几个球
node m[15];
int main(){
    //输入m[i].s 的字符串时为 数组的上界
    for(int i=1;cin>>m[i].s;i++){
        //每次输入·的处理 ：
        //是否为一击全中呢
        if(m[i].s[0]=='/'){
            //根据规则 第一击为全中 则加分10 
            m[i].num1=10;
            m[i].num2=10;
            m[i].flag=2;
        }else if(m[i].s[1]=='/'){
            //两击全中
            m[i].num1=m[i].s[0]-'0';  //减去字符0
            m[i].num2=10; //第二球的得分
            m[i].flag=1; //加后面一局的得分
        }else {
            //除开以上可能 则为没有全中 不加分
            m[i].num1=m[i].s[0]-'0';//第一局的得分
            m[i].num2=m[i].num1+m[i].s[1]-'0'; //第二局的得分  
        
        }
    } 

    int ans = 0;
    for(int i=1;i<=10;i++){
      ans+=m[i].num2;// 先加上自身,两球总分
      if(m[i].flag==1) //判断加分机制 ，1 词或者两次
      {
          ans+=m[i+1].num1;
      }else if(m[i].flag==2){
          //先把下一局的十分加上,以及下两局的得分
          ans+=10+m[i+2].num1;
      }else{
          //下局的没有一次全中
          ans+=m[i+1].num2; //下局两个球总分  1-10局的所有的情况
      }
    }

    cout << ans << endl;
    return 0;
}


