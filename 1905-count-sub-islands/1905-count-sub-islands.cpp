class Solution {
public:
bool check(int i , int j ,vector<vector<int>>& grid1, vector<vector<int>>& grid2,int n , int m){

    if(i <0 || j <0 || i >=n || j >=m){
        return true;
    }

 

    if(grid2[i][j] !=1){
        return true;
    }

    
        grid2[i][j]=-1;

        // if(grid2)

        bool res = (grid1[i][j]);


        bool up = check(i-1 , j , grid1, grid2, n , m);
        bool down = check(i+1, j , grid1, grid2, n ,m);
        bool r = check(i , j +1, grid1, grid2, n ,m);
        bool l = check(i, j-1 , grid1, grid2, n,m);


        return (res && up && r&& l&& down);

}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int n = grid1.size();
        int m = grid2[0].size();
        int cnt =0;

        for(int i =0 ; i< n; i++){
            for(int j =0 ;j <m ; j++){
                if(grid2[i][j] ==1 && check(i,j,grid1, grid2,n,m)){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};