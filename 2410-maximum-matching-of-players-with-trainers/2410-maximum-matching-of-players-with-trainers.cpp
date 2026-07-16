class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        sort(players.begin(), players.end());
        sort( trainers.begin(),  trainers.end());

        int i =0 ;
         int j =0;
         int n =  trainers.size();
int m = players.size();
int cnt =0;
         while( i<m && j <n ){

            if(players[i] <=  trainers[j]){
cnt++;
i++;
            }
            j++;
         }
         return cnt;
        
    }
};