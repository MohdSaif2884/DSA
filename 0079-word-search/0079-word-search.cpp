class Solution {
public:
int n ;
 int m ;
bool dfs(vector<vector<char>>& board, string & word, int i , int j , int index){
    if(index == word.size()){
        return true;
    }

     

    if(i>= n || j >=m || i <0 || j <0 || board[i][j] != word[index] ){
        return false;
    } 
    char ch = board[i][j];
    board[i][j]= '*';

   bool found =  dfs(board, word, i+1, j , index+1)||
    dfs(board, word, i-1, j, index+1)||
    dfs(board, word, i, j+1, index+1)||
    dfs(board, word, i, j-1, index+1);

    board[i][j] = ch;
    return found;
}
    bool exist(vector<vector<char>>& board, string word) {
         n = board.size();
         m =board[0].size();

        for(int i =0 ;i<n ; i++){
            for(int j =0 ; j <m ; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word,i , j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};