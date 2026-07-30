class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
         int m = grid[0].size();
         int dup =0;
         int sum =0;
         unordered_map<int, int>mp;
         for(int i =0 ; i <n ;i++){
            for(int j =0 ; j <m ; j++){
if(mp.find(grid[i][j]) != mp.end()){
    dup = grid[i][j];
}else{
sum+= grid[i][j];
}
mp[grid[i][j]]++;  
            }
         }
int a  = n*m;
         int total ;
         total= a*(a+1)/2;

        //  return ({dup , total - sum});
        return {dup, total - sum};

        
    }
};