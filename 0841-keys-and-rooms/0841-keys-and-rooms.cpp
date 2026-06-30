class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<vector<int>>adj(n);
         for(int i =0 ; i<n ;i++){
            for(auto &it:rooms[i]){
                adj[i].push_back(it);

            }
         }
         vector<int>vis(n, -1);

         queue<int>q;
         q.push(0);
         vis[0]=1;
         
         while(!q.empty()){
            auto crnt = q.front();
            q.pop();

            for(auto v: adj[crnt]){
                if(vis[v] ==-1){
                    vis[v] =1;
                    q.push(v);
                }
            }
         }

         for(int i =0 ; i <n ; i++){
            if(vis[i] ==-1){
                return false;
            }
         }
        return true;
    }
};