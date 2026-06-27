class Solution {
public:

void dfs(int i , int j ,vector<vector<int>>& grid , int  &area, int n , int m){
    // int n = grid.size();
    // int m = grid[0].size();

    if(i <0|| j <0 || i >=n || j >=m){
        return ;
    }

    if(grid[i][j] == 0){
        return ;
    }

    area++;
    grid[i][j] =0;
    dfs(i +1, j , grid, area, n , m);
    dfs(i -1,j, grid, area, n , m);
    dfs(i , j +1, grid, area, n , m);
    dfs(i , j-1, grid, area, n , m);


}
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;


        for(int i =0 ;i<n ; i++){
            // int area =0;
            for(int j =0 ; j<m ; j++){
                if(grid[i][j] == 1){
                    int area =0;
                    dfs( i , j , grid, area, n , m);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
        
    }
};