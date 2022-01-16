class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board){
        for (int i = 0; i < 9; i ++ ){
            unordered_map<char, bool> hashmap1, hashmap2;
            for (int j = 0; j < 9; j ++ ){
                if (board[i][j] == '.'){}
                else{
                    if (!hashmap1.count(board[i][j])){
                        hashmap1[board[i][j]] = true;
                    }else{
                        return false;
                    }
                }
                if (board[j][i] == '.'){}
                else{
                    if (!hashmap2.count(board[j][i])){
                        hashmap2[board[j][i]] = true;
                    }else{
                        return false;
                    }
                }
                if (i % 3 == 0 && j % 3 == 0 && !solve(board, i, j)){
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int i1, int j1){
        unordered_map<char, bool> hashmap;

        for (int i = i1; i < i1 + 3; i ++ ){
            for (int j = j1; j < j1 + 3; j ++ ){
                if (board[i][j] == '.') continue;
                if (!hashmap.count(board[i][j])){
                    hashmap[board[i][j]] = true;
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};