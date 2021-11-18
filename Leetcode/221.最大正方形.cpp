class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxn = 0;
        int f[matrix.size() + 1][matrix[0].size() + 1];
        memset(f, 0, sizeof(f));

        for(int i = 0; i < matrix.size(); i ++ ){
            for(int j = 0; j < matrix[0].size(); j ++ ){
                if (i == 0 || j == 0){
                    f[i][j] = (matrix[i][j] == '1' ? 1 : 0);
                    maxn = max(maxn, f[i][j]);
                    continue;
                }
                if (matrix[i][j] == '1'){
                    f[i][j] = 1;
                    if (f[i - 1][j] != 0 && f[i][j - 1] != 0 && f[i - 1][j - 1] != 0){
                        f[i][j] += minn(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]);
                    }
                }
                maxn = max(maxn, f[i][j]);
            }
        }
        
        return maxn * maxn;
    }

    int minn(int a, int b, int c){
        int mid = min(a, b);
        return min(c, mid);
    }
};