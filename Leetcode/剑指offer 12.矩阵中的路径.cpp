class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i ++ ){
            for(int j = 0; j < board[0].size(); j ++ ){
                if(solve(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }

    bool solve(vector<vector<char>>& board, string word, int i, int j, int k) {
        /*当前的值不相等，i或j越界*/
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[k]){
            return false;
        }
        /*如果当前匹配的是最后一个，就直接返回true*/
        if(k == word.size() - 1){
            return true;
        }

        /*标志当前位置已经被走过了*/
        board[i][j] = ' ';
        /*往四个方向进行判断（这个位置就需要减枝）*/
        bool res = solve(board, word, i + 1, j, k + 1) || solve(board, word, i - 1, j, k + 1) || 
                      solve(board, word, i, j + 1, k + 1) || solve(board, word, i , j - 1, k + 1);
        /*恢复原来的位置*/
        board[i][j] = word[k];
        
        return res;
    }
};