class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> flag(board.size(), vector<int>(board[0].size(), 0));
        //init
        for (int i = 0; i < board[0].size(); i ++ ){
            if (board[0][i] == 'O'){
                deepsearch(board, flag, 0, i);
            }
            if (board[board.size() - 1][i] == 'O'){
                deepsearch(board, flag, board.size() - 1, i);
            }
        }
        for (int i = 0; i < board.size(); i ++ ){
            if (board[i][0] == 'O'){
                deepsearch(board, flag, i, 0);
            }
            if (board[i][board[0].size() - 1] == 'O'){
                deepsearch(board, flag, i, board[0].size() - 1);
            }
        }

        //main
        for (int i = 1; i < board.size() - 1; i ++ ){
            for (int j = 1; j < board[0].size() - 1; j ++ ){
                if (flag[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';//这里写成了==，de了好久...
                }
            }
        }
    }

    void deepsearch(vector<vector<char>>& board, vector<vector<int>>& flag, int x, int y){
        if (flag[x][y] == 1) return ;
        flag[x][y] = 1;
        if (x + 1 < board.size() && board[x + 1][y] == 'O') deepsearch(board, flag, x + 1, y);
        if (x - 1 >= 0 && board[x - 1][y] == 'O') deepsearch(board, flag, x - 1, y);
        if (y + 1 < board[0].size() && board[x][y + 1] == 'O') deepsearch(board, flag, x, y + 1);
        if (y - 1 >= 0 && board[x][y - 1] == 'O') deepsearch(board, flag, x, y - 1);
    }
};