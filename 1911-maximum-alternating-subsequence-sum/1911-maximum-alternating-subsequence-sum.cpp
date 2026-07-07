class Solution {
public:
int n;
long long solve(vector<int>& nums, vector<vector<long long>>& dp, int i , bool flag){
    if(i >= n){
        return 0;
    }
    if(dp[i][flag] != -1){
        return dp[i][flag];
    }

    long long left = solve(nums, dp , i+1, flag);
    long long val= nums[i];

    if(flag == false){
        val = -val;
    }
    long long take = solve(nums, dp, i+1, !flag ) + val;

    return dp[i][flag] = max(left, take);


}
    long long maxAlternatingSum(vector<int>& nums) {
 n = nums.size();

        // vector<int>dp(n , -1);
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(nums, dp ,0, true);
        
    }
};