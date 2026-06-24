 class Solution {
public:
    int minCost(int maxTime,
                vector<vector<int>>& edges,
                vector<int>& passingFees) {

        int n = passingFees.size();

        vector<pair<int,int>> adj[n];

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int t = e[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<int> minTime(n, INT_MAX);
        vector<int> minCost(n, INT_MAX);

        pq.push({passingFees[0], 0, 0});

        minTime[0] = 0;
        minCost[0] = passingFees[0];

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int cost = cur[0];
            int node = cur[1];
            int time = cur[2];

            if (node == n - 1)
                return cost;

            for (auto &[nei, t] : adj[node]) {

                int newTime = time + t;

                if (newTime > maxTime)
                    continue;

                int newCost =
                    cost + passingFees[nei];

                if (newCost < minCost[nei]) {

                    minCost[nei] = newCost;
                    minTime[nei] = newTime;

                    pq.push({
                        newCost,
                        nei,
                        newTime
                    });
                }
                else if (newTime < minTime[nei]) {

                    minTime[nei] = newTime;

                    pq.push({
                        newCost,
                        nei,
                        newTime
                    });
                }
            }
        }

        return -1;
    }
};