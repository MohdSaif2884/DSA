class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<double>dis(n ,0.0);
        dis[start_node] =1;
        priority_queue<pair<double, int>> q;
    vector<pair< int, double>>adj[n];
        
        for(int i =0 ;i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            double w = succProb[i];

            adj[u].push_back({v, w});
            adj[v].push_back({u,w});
        }

        // vector<int>vis(n , -1);
        // vector<int>dis(n , INT_MAX);
        dis[start_node] =1.0;

        q.push({1.0,start_node});
        while(!q.empty()){
            auto e = q.top();
            q.pop();
             double p = e.first;
             int u = e.second;

             if(u == end_node){
                return p;
             }
            //  if()

            for(auto v: adj[u]){
                int nei = v.first;
                double newp = v.second;
                if(dis[nei] < newp * p){
                    dis[nei] = newp*p;
                    q.push({p*newp,nei  });
                }

                
            }     
        }
        return 0;


        
    }
};