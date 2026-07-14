class Solution {
public:

int f(int i , int j ,vector<vector<int>>& matrix,vector<vector<int>>& dp  ){
    if(j <0 || j>= matrix.size()){
        return 1e9;
    }

    if(i==0){
        return matrix[i][j];
    }

    if(dp[i][j] != INT_MAX){
        return dp[i][j];
    }
int s = f(i-1,j, matrix, dp)+ matrix[i][j];
int ld=   f(i-1,j-1, matrix, dp)+ matrix[i][j];
int rd=  f(i-1,j+1, matrix, dp)+ matrix[i][j];

return dp[i][j] = min(s, min(ld,rd));

}
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int n = matrix.size() - 1;

        vector<vector<int>> dp(matrix.size(),
                               vector<int>(matrix[0].size(), INT_MAX));

        int mini = INT_MAX;

        for (int j = 0; j < matrix[0].size(); j++) {
            mini = min(mini, f(n, j, matrix, dp));
        }

        return mini;
    }
};