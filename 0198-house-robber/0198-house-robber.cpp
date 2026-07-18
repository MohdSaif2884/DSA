class Solution {
public:
int n ;
int f(int i ,   vector<int>&dp, vector<int>& nums ){

if(i ==0){
    return nums[0];
}
if(i <0){
    return 0;
}
if(dp[i] !=-1){
    return dp[i];
}
   int skip = f(i-1,dp, nums);
   int take = -1e8;
   if(i >0){
    take = f(i-2, dp, nums) + nums[i];
   }

   return dp[i] = max(skip , take);

}
    int rob(vector<int>& nums) {
         n = nums.size();
        vector<int>dp(n+1, -1);
return f(n-1,dp,nums);
        
        
        
    }
};