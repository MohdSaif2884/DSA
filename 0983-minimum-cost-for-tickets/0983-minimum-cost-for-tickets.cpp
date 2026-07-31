class Solution {
public:
int f(int i , vector<int>&dp, vector<int>& day, vector<int>& costs, int n ){
    if(i ==n){
        return 0;
    }
    if( i >n){
        return 1e9;
    }

    if(dp[i] !=-1){
        return dp[i];
    }
    int day1 = f(i +1, dp, day, costs, n)+ costs[0];

    int day7 = 1e9;
    int j =i;
    int maxday = day[i] +7;
    while( j <n && day[j] < maxday){
        j++;
    }

    day7 = costs[1] + f(j , dp, day , costs , n);

    maxday = day[i] +30;
    j =i;
    int day30 = 1e9;
    while( j <n && day[j] <maxday){
        j++;
    }
    day30 = costs[2]+ f(j , dp , day , costs , n);

    return dp[i] = min({day1, day7 , day30});






}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n +1, -1);

return f(0 , dp, days, costs, n);
        
    }
};