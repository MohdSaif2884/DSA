class Solution {
public:
void dfs(int node , int n ,  vector<vector<int>>&ans,vector<vector<int>>& graph, vector<int>&temp){
    
    temp.push_back(node);
    if(node == n){
        ans.push_back(temp);
    }else{
        for(auto v: graph[node]){
            dfs(v, n, ans,graph,temp);
        }
    }

    temp.pop_back();


}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(0, n-1,ans,graph,temp);
        return ans;

        
    }
};