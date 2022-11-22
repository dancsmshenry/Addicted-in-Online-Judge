struct record {
    record():up(0), down(0), left(0), right(0) {}
    int up;
    int down;
    int left;
    int right;
};

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> f(n, vector<int>(n, 1));
        for (auto& mine: mines) {
            f[mine[0]][mine[1]] = 0;
        }

        vector<vector<record>> records(n, vector<record>(n, record{}));
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (f[i][j] == 0) continue;
                if (i == 0) records[i][j].up = 1;
                else records[i][j].up = records[i - 1][j].up + 1;
                if (j == 0) records[i][j].left = 1;
                else records[i][j].left = records[i][j - 1].left + 1;
            }
        }

        for (int i = n - 1; i >= 0; -- i) {
            for (int j = n - 1; j >= 0; -- j) {
                if (f[i][j] == 0) continue;
                if (i == n - 1) records[i][j].down = 1;
                else records[i][j].down = records[i + 1][j].down + 1;
                if (j == n - 1) records[i][j].right = 1;
                else records[i][j].right = records[i][j + 1].right + 1;
            }
        }

        int res{};
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (f[i][j] == 0) continue;
                if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                    res = max(res, 1);
                    continue;
                }
                int ans = min(INT_MAX, records[i - 1][j].up);
                ans = min(ans, records[i + 1][j].down);
                ans = min(ans, records[i][j - 1].left);
                ans = min(ans, records[i][j + 1].right);
                res = max(res, ans + 1);
            }
        }
        return res;
    }
};