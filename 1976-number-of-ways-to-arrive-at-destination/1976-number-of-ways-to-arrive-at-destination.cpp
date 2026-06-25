 class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<pair<int,int>> adj[n];

        for (auto &it : roads) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        const int mod = 1e9 + 7;

        priority_queue<
            pair<long long,long long>,
            vector<pair<long long,long long>>,
            greater<pair<long long,long long>>
        > pq;

        vector<long long> path(n,0);
        vector<long long> dis(n,LLONG_MAX);

        dis[0] = 0;
        path[0] = 1;

        pq.push({0,0});

        while(!pq.empty()) {
            auto e = pq.top();
            pq.pop();

            long long time = e.first;
            long long node = e.second;

            if (time > dis[node]) continue;

            for (auto &nei : adj[node]) {
                long long neinode = nei.first;
                long long neitime = nei.second;

                if (time + neitime < dis[neinode]) {
                    dis[neinode] = time + neitime;
                    path[neinode] = path[node];
                    pq.push({dis[neinode], neinode});
                }
                else if (time + neitime == dis[neinode]) {
                    path[neinode] =
                        (path[neinode] + path[node]) % mod;
                }
            }
        }

        return path[n-1] % mod;
    }
};