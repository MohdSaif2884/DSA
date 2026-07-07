class Solution {
public:
int solve(vector<int>& nums,vector<int>&dp, int i , int n){
    if( i >=n){
        return 0;
    }
    if(dp[i] !=-1){
        return dp[i];
    }
    int skip = solve(nums, dp, i+1,n);
    int take = solve(nums, dp, i+2,n)+ nums[i];

    return dp[i] = max(skip, take);

}
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        vector<int>dp2(n+1, -1);
        if(n ==1){
            return nums[0];
        }

        if(n ==2){
            return max(nums[0], nums[1]);
        }
        return max(solve(nums, dp , 0, n-1), solve(nums, dp2, 1, n));
        
    }
};