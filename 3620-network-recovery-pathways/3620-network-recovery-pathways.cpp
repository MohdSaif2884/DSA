 class Solution {
public:
     
    bool check(int mid, int n, vector<vector<pair<int, int>>>& adj, vector<bool>& online, long long k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        q.push({0, 0});
        
        vector<long long> dist(n, 1e18);
        dist[0] = 0;

        while(!q.empty()) {
            auto e = q.top();
            q.pop();
            long long w = e.first;
            int node = e.second;

            if(w > dist[node]) {
                continue;
            }

            if(node == n - 1) {
                return dist[node] <= k;
            }

            for(auto v : adj[node]) {
                int pad = v.first;
                int neww = v.second;

                if(!online[pad]) {
                    continue;
                }
                
                if (neww < mid) {
                    continue;
                }

                if(w + neww < dist[pad]) {
                    dist[pad] = w + neww;
                    q.push({dist[pad], pad});
                }
            }
        }
        return false;
    }
    
     
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        
         
        int n = online.size(); 
        
        vector<vector<pair<int, int>>> adj(n);
        int maxe = 0;
        
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            maxe = max(maxe, e[2]); 
        }

        int l = 0; 
        int h = maxe;
        int ans = -1; 
        
        while(l <= h) {
            int mid = l + (h - l) / 2; 
            
            if(check(mid, n, adj, online, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};