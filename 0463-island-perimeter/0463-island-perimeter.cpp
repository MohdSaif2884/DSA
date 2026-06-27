class Solution {
public:
void dfs(vector<vector<int>>& grid , int i , int j , int &prem ){
      int n = grid.size();
         int m = grid[0].size();

         if(i >=n ||  j>= m || i <0 || j <0|| grid[i][j] == 0){
            prem++;
            return ;
         }
         if(grid[i][j]==2){
            return ;
         }

         grid[i][j]=2;
         
         dfs(grid, i +1, j , prem);
         dfs(grid, i-1, j , prem);
         dfs(grid, i , j+1, prem);
         dfs(grid, i , j-1, prem);

    
}
    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
         int m = grid[0].size();
         int prem =0;

         for(int i =0 ; i<n ;i++){
            for(int j =0; j<m ; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i , j, prem);
                }
            }
         }
         return prem;
        
    }
};