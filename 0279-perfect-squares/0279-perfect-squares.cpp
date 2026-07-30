class Solution {
public:
int f(int n ,  vector<int>&dp ){
    if( n==0){
        return 0;
    }

    if( n <0){
        return INT_MAX;
    }


    if(dp[n] !=-1){
        return dp[n];
    }

    int ans = INT_MAX;
    for(int i =1; i *i<= n ; i++){
        int res = 1+ f(n - i*i, dp);

        ans = min(res, ans);
    }

    return dp[n] = ans;
}
    int numSquares(int n) {

        vector<int>dp(n+1 , -1);
        return f(n, dp);
        
    }
};