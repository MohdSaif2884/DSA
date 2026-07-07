class Solution {
public:
int solve(vector<int>&nums, vector<int>&dp, int i, int n){
    if(i >=n ){
        return 0;
    }
    if(dp[i] !=-1){
        return dp[i];
    }
int pick = solve(nums, dp, i+2, n)+ nums[i];
int skip = solve(nums, dp , i+1, n);

return dp[i] = max(pick, skip);

    return dp[i] = max(pick , skip);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solve(nums, dp, 0, n);
        // return max(solve(nums, dp , n -1), solve(nums, dp , n-2));
        
    }
};