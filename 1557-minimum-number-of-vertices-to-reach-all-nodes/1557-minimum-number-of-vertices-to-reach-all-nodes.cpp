class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<int>indeg(n , 0);

        vector<vector<int>>edg(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            edg[u].push_back(v);
            indeg[v]++;
        }
        vector<int>ans;

        for(int i =0 ; i<n ; i++){
            if(indeg[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;


        
    }
};