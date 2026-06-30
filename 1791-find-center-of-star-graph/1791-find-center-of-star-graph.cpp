class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int>indeg(n+2, 0);
        vector<int>outdeg(n+2,0);

        vector<vector<int>>adj(n+2);
        for(auto & e: edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            // indeg[v]++;
            // outdeg[u]++;

            indeg[u]++;
            // outdeg[v]++;
            indeg[v]++;


        }


        for(int i =1; i<= n ; i++){
            if(indeg[i] == n-1){
                return i;
            }
        }
        return -1;
        
    }
};