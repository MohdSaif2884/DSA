class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>>edj(n);
        vector<int>vis(n , -1);

        for(auto & it: edges){
            int u = it[0];
            int v = it[1];

            edj[u].push_back(v);
            edj[v].push_back(u);

        }


        queue<int>q;
        vis[source] =1;
        q.push(source);
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            if(node == destination){
                return true;
            }

            for(auto v:edj[node]){
                if(vis[v] ==-1){
                    vis[v] =1;
                    q.push(v);
                }

            }
        }
        return false;
        
    }
};