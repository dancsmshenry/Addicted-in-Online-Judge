class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        vector<vector<int>> f(n, vector<int> (n, 0));

        for (int i = 0; i < n; ++ i ) {
            for (int j = 0; j < n - i; ++ j ) {
                if (i <= 1 || f[j + 1][j + i - 1] != 0) {
                    f[j][j + i] = (s[j] == s[j + i]) ? 1 : 0;
                }

                res += f[j][j + i];
            }
        }

        return res;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;

        for (int i = 0; i < 2 * n - 1; ++ i) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                -- l;
                ++ r;
                ++ res;
            }
        }

        return res;
    }
};