class Solution {
public:
int f(int i , vector<int>& days, vector<int>& cost,vector<int>&dp, int n){
if(i >= n){
    return 0;
}

if(dp[i] !=-1){
    return dp[i];
}

int day1 = cost[0]+ f(i+1, days, cost,dp , n );
int j =i;
int maxday = days[i]+7;
while( j <n && days[j] < maxday ){
    j++;
}
// j =i;
int day7 = cost[1]+ f(j, days, cost, dp, n);
j =i;
maxday = days[i]+30;
while(j < n &&days[j]< maxday ){
    j++;
}

int day30 = cost[2] + f(j , days, cost , dp, n);

return dp[i] = min(day1,min(day7, day30));




}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1, -1);
        return f(0 , days, costs , dp, n);
        
    }
};