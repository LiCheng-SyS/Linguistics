#include<iostream>
using namespace std;

char str[1005];
int main(){
    long long ans =0, now =1 ,count_cnt=0;
     cin >> str;
     for(int i=0;i<str[i];i++){
         if(i<13){
            //now windowns
            now*=str[i]-'0';           
         } else if(str[i]!='0')
         {
            now*=str[i]-'0';   
         }else{
            count_cnt++;
         }

         if(i>=13){
            //则窗体向后走
             if(str[i-13]!='0'){
                 now /=str[i-13]-'0';
             } 
             else{
                 count_cnt--;
             }
         }
         if(count_cnt ==0){
             ans=max(ans,now);
         }
     }
    cout << ans <<endl;  
    return 0; 

}
