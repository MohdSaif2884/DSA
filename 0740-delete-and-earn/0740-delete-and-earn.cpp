class Solution {
public:

int f(int i , vector<int>&value,  vector<int>&dp ){
if(i ==0){
    return value[0];
}

if(i <0){
    return 0;
}
if(dp[i] !=-1){
    return dp[i];
}

int skip = f(i -1,value, dp)+0;
int take = f(i-2, value, dp)+ value[i];

return dp[i] = max(skip , take);


}
    int deleteAndEarn(vector<int>& nums) {

        int maxi = *max_element(nums.begin(), nums.end());
        vector<int>value(maxi+1, 0);

        for(auto x: nums){
            value[x]+= x;
        }

        vector<int>dp(maxi+1, -1);

return f(maxi,value,dp);
        
    }
};