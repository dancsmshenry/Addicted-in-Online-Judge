class Solution {
private:
    vector<int> res;
    int n{}, m{};
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // flagΪtrue��ʱ�������Ϸ��ߣ������������ұ߿����������濴
        // flagΪfalse��ʱ�������·��ߣ����׺��������濴�������ұ߿�
        n = mat.size();
        m = mat[0].size();
        solve(mat, 0, 0, true);
        return res;
    }

    void solve(vector<vector<int>>& mat, int i, int j, bool flag) {
        if (flag == true) {
            while (i >= 0 && i < n && j >= 0 && j < m) {
                res.push_back(mat[i][j]);
                -- i;
                ++ j;
            }
            ++ i;
            -- j;
            if (j + 1 < m) {
                solve(mat, i, j + 1, false);
            } else if (i + 1 < n) {
                solve(mat, i + 1, j, false);
            }
            return ;
        }
        while (i >= 0 && i < n && j >= 0 && j < m) {
            res.push_back(mat[i][j]);
            ++ i;
            -- j;
        }
        ++ j;
        -- i;
        if (i + 1 < n) {
            solve(mat, i + 1, j, true);
        } else if (j + 1 < m) {
            solve(mat, i, j + 1, true);
        }
    }
};