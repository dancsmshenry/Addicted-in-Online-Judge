class Solution {
private:
    int res{};
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> f(n, vector<int> (n, 0));
        for (auto& rela: relation) {
            f[rela[0]][rela[1]] = 1;
        }

        dfs(f, k, 0, n - 1);
        return res;
    }

    void dfs(vector<vector<int>>& f, int k, int begin, int end) {
        if (k == 0) {
            if (begin == end) ++ res;
            return ;
        }

        for (int i = 0; i < f[begin].size(); ++ i) {
            if (f[begin][i] == 1) {
                dfs(f, k - 1, i, end);
            }
        }
    }
};

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relations, int k) {
        vector<vector<int>> dp(k + 1, vector<int> (n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < k; ++ i) {
            for (auto& relation: relations) {
                dp[i + 1][relation[1]] += dp[i][relation[0]];
            }
        }

        return dp[k][n - 1];
    }
};