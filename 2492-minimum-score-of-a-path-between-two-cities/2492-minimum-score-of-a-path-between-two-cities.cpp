class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<int>>adj[n+1];
        for(auto &it: roads){
int u = it[0];
int v = it[1];
int w = it[2];

adj[u].push_back({v,w});
adj[v].push_back({u,w});
        }

        // priority_queue<vector<int>
        vector<int>vis(n+1 , -1);
        int ans = INT_MAX;
        queue<int>q;

        q.push(1);
        vis[1] =1;
        while(!q.empty()){
            auto e = q.front();
            q.pop();
           

            for(auto &v: adj[e]){
                // if(vis[v] ==-1){
int nei = v[0];
int neww = v[1];

if(ans >neww){
    ans = neww;
}

if(vis[nei] == -1){
    vis[nei] =1;
    q.push(nei);
}
 

                }
            }



        
        return ans;
    }
};