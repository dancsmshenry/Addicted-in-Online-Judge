class Solution {
private:
    int n{};
    int m{};
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; ++ i) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }

        for (int i = 0; i < m; ++ i) {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }

        for (auto&& boar: board) {
            for (auto&& boa: boar) {
                if (boa == 'O') {
                    boa = 'X';
                } else if (boa == 'Y') {
                    boa = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O') {
            return ;
        }
        board[i][j] = 'Y';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};