class Solution {
public:
bool f(int i , int sum ,vector<int>& nums ,vector<vector<int>>&dp ){

    if(sum ==0){
        return 1;
    }

    if(i ==0){
        if(sum == nums[0]){
            return true;
        }else{
            return false;
        }
    }

if(dp[i][sum] != -1){
    return dp[i][sum];
}
    bool leave = f( i -1, sum , nums,dp);
bool take =false;
    if(sum >= nums[i]){
        take = f(i-1, sum -nums[i], nums,dp);
    }

    return dp[i][sum]=(take || leave);
}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
         
        int sum =0;
        for(int i =0 ; i<n; i++){
            sum += nums[i];
        }
        vector<vector<int>>dp(n,vector<int>(sum/2 +1, -1));

        if(sum %2 !=0){
            return false;
        }

       return f(n-1,sum/2, nums, dp);
        
    }
};