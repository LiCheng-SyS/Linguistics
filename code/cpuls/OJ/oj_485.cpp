#include<iostream>
using namespace std;


int  n , num[105], sum;
int main(){
    cin>> n;
    for(int i=0;i<=n;i++){
        cin >> num[i];
        sum+=num[i]; //先有总和   
    }

    int avg =sum/n, ans =0;//还有个平均值
    for(int i=0;i<=n-1;i++){
        if(num[i]!=avg) //如果不是平均值 必须要要移动了
        {
           ans++;
           num[i+1]+=num[i]-avg; //不管是 借还是减 值就会变小
           num[i]=avg;
        }
    }

    cout << ans <<endl;

    return 0;
}
