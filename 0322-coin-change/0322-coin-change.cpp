class Solution {
public:
int f(int i , int t,vector<int>& coins,  vector<vector<int>>&dp){
    if (t == 0) return 0;
if (t < 0) return 1e9;
    if(i==0){
        if(t%coins[0]==0){
            return t/ coins[0];
        }else{
            return 1e9;
        }
    }

    if(dp[i][t] !=-1){
        return dp[i][t];
    }

    int leave = f(i-1, t, coins,dp);

    int take = 1e9;
    if(t>= coins[i]){
      take = 1+ f(i, t- coins[i], coins, dp);
    }

    return dp[i][t] = min(take , leave);





}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n , vector<int>(amount+1, -1));

int ans =f(n-1,amount, coins, dp);
if(ans == 1e9){
    return -1;
}
return ans;
        
    }
};