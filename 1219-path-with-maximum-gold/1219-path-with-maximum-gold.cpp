class Solution {
public:
int n ;
int m ;
int dfs(vector<vector<int>>& grid, int i , int j ){

    

    if(i >= n || j >= m || i <0 || j <0|| grid[i][j] ==0){
        return 0;
    }
    // gold+= grid[i][j];
int g = grid[i][j];
grid[i][j] =0;

 int maxg = std::max({
    dfs(grid, i + 1, j), 
    dfs(grid, i - 1, j), 
    dfs(grid, i, j + 1), 
    dfs(grid, i, j - 1)
});


grid[i][j]= g;
return g+ maxg;



}
    int getMaximumGold(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        int maxi = INT_MIN;
        int gold =0;

        for(int i =0 ; i<n ; i++){
            for(int j =0 ; j <m ; j++){
                if( grid[i][j] >0){
                   int gold=  dfs(grid, i , j );
                    maxi = max(maxi , gold);

                }
            }
        }
        if(maxi == INT_MIN)return 0;
        return maxi;
        
    }
};