 class Solution {
public:

    vector<pair<int,int>> dir = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };

    bool dfs(int i, int j,
             int pi, int pj,
             vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;

        for(auto &d : dir){

            int ni = i + d.first;
            int nj = j + d.second;
 
            if(ni < 0 || nj < 0 || ni >= n || nj >= m)
                continue;

         
            if(grid[ni][nj] != grid[i][j])
                continue;

          
            if(ni == pi && nj == pj)
                continue;

           
            if(vis[ni][nj])
                return true;

        //    S
            if(dfs(ni, nj, i, j, grid, vis))
                return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(!vis[i][j]){

                    if(dfs(i,j,-1,-1,grid,vis))
                        return true;
                }
            }
        }

        return false;
    }
};