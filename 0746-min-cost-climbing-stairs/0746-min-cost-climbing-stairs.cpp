class Solution {
public:
int solve(vector<int>& cost, vector<int>&dp, int i){
    if(i ==0){
        return cost[0];
    }
    if(i ==1){
        return cost[1];
    }

    if(dp[i] != -1){
        return dp[i];
    }

    int l = solve(cost, dp, i-1) + cost[i];
    int r = solve(cost, dp, i-2)+cost[i];
    return dp[i] = min(l,r);
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n ==0){
            return 0;
        }
        vector<int>dp(n+1, -1);
        return min(
            solve(cost,dp,n-1),solve(cost, dp, n-2)
        );
        


        
    }
};