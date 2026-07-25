class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int land =0;

        queue<pair<int,int>>q;
        int level =-1;
        for(int i =0 ; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                if(grid[i][j]== 1){
                    q.push({i,j});
                    land++;
                }
            }
        }
// int xd[4]= {1,-1,0,0};
// int yd[4]= {0,0,1,-1};
//         while(!q.empty()){
//             int size = q.size();

//             for(int i =0 ;i<size; i++){
//             auto front = q.front();
//             q.pop();


//             for(int d =0 ; d<4; d++){
//                 int nx = front.first + xd[d];
//                 int ny = front.second + yd[d];

//                 if(nx>=0&& ny>= 0 && nx<n && ny <m && grid[nx][ny]==0){
//                     q.push({nx,ny});
//                     grid[nx][ny]=1;
//                 }
//             }
//             }level++;
//         }

int xd[4] = {0 ,0, 1,-1};
int yd[4]={1,-1,0 ,0};
while(!q.empty()){
    int size = q.size();
    for(int i =0 ; i<size; i++){
        auto f = q.front();
        q.pop();

        int x= f.first;
        int y = f.second;

        for(int d =0 ; d<4 ; d++){
            int newx = x + xd[d];
            int newy = y + yd[d];

            if(newx>=0 && newy>=0 && newx<n && newy <m && grid[newx][newy] == 0){
                q.push({newx, newy});
                grid[newx][newy] = 1;
            }
        }
    }
    level++;
}





        if(land == 0 || land == n*m)
    return -1;
return level;
        
    }
};