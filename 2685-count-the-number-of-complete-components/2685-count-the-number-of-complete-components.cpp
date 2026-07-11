class Solution {
public:
void dfs(int i ,  vector<vector<int>>&adj, vector<int>&vis , int &node, int &edge){

    vis[i]=1;
    edge+=adj[i].size();
    node++;
    for(auto v: adj[i]){
        if(!vis[v]){
            dfs(v, adj, vis, node, edge);
        }
    }




}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int comp =0;
    vector<int>vis(n,0);
    for(int i =0 ; i<n ; i++){
        if(!vis[i]){
            int node =0;
            int edge =0;
            dfs(i ,adj, vis,node, edge);

            edge= edge/2;

            if(edge == (node*(node-1))/2){
                comp++;
            }
        }
    }
    return comp;
        
    }
};