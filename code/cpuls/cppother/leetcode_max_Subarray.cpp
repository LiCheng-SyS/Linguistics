#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;





int maxSubArray(vector<int>& nums) {
    int fin=nums[0],ans=nums[0];
    for(int i=1;i<nums.size();i++){
         
         //fin为最终解,动态规划的题目,比较当前一位和已存位的和动态相加的数值
         ans=max(nums[i],ans+nums[i]);
         fin= max(ans,fin);
    }
    return fin;
        
}
int main(){
      int arr[]={-2,1,-3,4,-1,2,1,-5,4};
      vector<int>setArray(arr,arr+9);
      int fin =maxSubArray(setArray);
      cout <<  fin  << endl;
      return 0;              
}
