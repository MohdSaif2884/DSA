class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>>q;
        vector<vector<int>>dis(n , vector<int>(m , -1));
        for(int i =0 ; i<n ; i++){
            for(int j =0 ; j <m ; j++){
                if(mat[i][j] == 0){
                    q.push({i , j});
                    dis[i][j] =0;
                }
            }
        }
int dx[4] ={0,0,1,-1};
int dy[4] = {1, -1, 0,0};
        while(!q.empty()){

            int size= q.size();

            for(int i =0 ; i<size; i++){
                auto f = q.front();
                q.pop();
                int x = f.first;
                int y = f.second;

                for(int d =0 ; d<4 ; d++){
                    int nx = x+ dx[d];
                    int ny = y + dy[d];

                    if(nx<n && ny <m && nx>=0 && ny >=0&& dis[nx][ny] == -1){
                        q.push({nx, ny});
                        dis[nx][ny] =  dis[x][y]+1;

                    }
                }
            }


        }
        return dis;
        
    }
};