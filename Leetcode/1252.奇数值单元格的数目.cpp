class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> f1(n, 0), f2(m, 0);

        for (auto& indice: indices) {
            ++ f1[indice[0]];
            ++ f2[indice[1]];
        }

        int res{};
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if ((f1[i] + f2[j]) % 2 == 1) {
                    ++ res;
                }
            }
        }

        return res;
    }
};