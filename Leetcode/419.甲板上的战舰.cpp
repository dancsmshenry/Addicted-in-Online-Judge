class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int result = board[0][0] == 'X' ? 1 : 0;

        /*init*/
        for (int i = 1; i < board[0].size(); i ++ ){
            if (board[0][i - 1] != 'X' && board[0][i] == 'X'){
                result ++ ;
            }
        }
        for (int i = 1; i < board.size(); i ++ ){
            if (board[i - 1][0] != 'X' && board[i][0] == 'X'){
                result ++ ;
            }
        }

        for (int i = 1; i < board.size(); i ++ ){
            for (int j = 1; j < board[0].size(); j ++ ){
                if (board[i][j] == 'X' && board[i][j - 1] != 'X' && board[i - 1][j] != 'X'){
                    result ++ ;
                }
            }
        }

        return result;
    }
};