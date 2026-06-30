class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<vector<int>>adj(n+1);
        vector<int>indeg(n+1,0);
        vector<int>outdeg(n+1,0);

        for(auto it: trust){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }

         

       for(int i =1; i<=n ; i++){
if(indeg[i] == n-1  && outdeg[i] ==0){
    return i;
}
       }

       return -1;
    //  return indeg[2];
        
    }
};