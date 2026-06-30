class Solution {
public:
void dfs(int i , int j ,vector<vector<int>>& grid){
     int n = grid.size();
        int m = grid[0].size();

        // grid[i][j]=1;

        if(i <0 || j <0 || i >=n ||j >=m ||grid[i][j] ==1){
            // dfs()return 
            return ;
        }
        grid[i][j]=1;

        dfs(i+1, j , grid);
        dfs(i-1, j , grid);
        dfs(i , j+1, grid);
        dfs(i , j-1, grid);


    
}
    int closedIsland(vector<vector<int>>& grid) {


        int n = grid.size();
        int m = grid[0].size();

        for(int i =0 ; i<n ; i++){
int j =0;
if(grid[i][j] ==0){
    dfs(i , j, grid);
}
j =m-1;
if(grid[i][j] ==0){
    dfs(i , j, grid);
}


        }



         for(int j =0 ; j <m ; j++){
            int i =0;
            if(grid[i][j] == 0){
                dfs(i , j, grid);
            }

            i = n -1;
            if(grid[i][j] == 0){
                dfs(i , j, grid);
            }
         }

int cnt =0;
         for(int i =0 ; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                if(grid[i][j] ==0){
                    dfs(i , j , grid);
                    cnt++;

                }
            }
         }
         return cnt;
        
    }
};