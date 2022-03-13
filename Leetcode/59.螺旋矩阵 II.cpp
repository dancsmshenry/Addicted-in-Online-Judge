class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n, 0));
        int top = 0, left = 0;
        int down = n - 1, right = n - 1;
        int count = 1;

        while (count <= n * n) {
            for (int i = left; i <= right; ++ i, ++ count) {
                res[top][i] = count;
            }
            top ++ ;
            
            for (int i = top; i <= down; ++ i, ++ count) {
                res[i][right] = count;
            }
            right -- ;

            for (int i = right; i >= left; -- i, ++ count) {
                res[down][i] = count;
            }
            down -- ;

            for (int i = down; i >= top; -- i, ++ count) {
                res[i][left] = count;
            }
            left ++ ;
        }

        return res;
    }
};