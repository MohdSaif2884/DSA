class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto &it: dislikes){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>color(n+1 , -1);
        for(int i =0 ; i<n ; i++){
            if(color[i] == -1){
                queue<int>q;
                q.push(i);
                color[i] =0;

                while(!q.empty()){
                    auto u = q.front();
                    q.pop();
                    for(auto &v: adj[u]){
                        if(color[v] ==-1){
                            color[v] = 1-color[u];
                            q.push(v);
                        }else if( color[v] == color[u]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
        
    }
};