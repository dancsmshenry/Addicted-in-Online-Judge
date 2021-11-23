class Solution {
public:
    int trap(vector<int>& height) {
        // //时间复杂度太高了，超时了
        // int n = height.size();
        // vector<vector<int>> f(n, vector<int>(n, 0));

        // //init
        // for (int i = 0; i < n - 1; i ++ ){
        //     f[i][i] = 0;
        //     f[i][i + 1] = 0;
        // }
        // f[n - 1][n - 1] = 0;

        // //dp
        // for (int i = 2; i < n; i ++ ){
        //     for (int j = 0; j < n - i; j ++ ){
        //         int mid = 0;
        //         for (int l = j, bianjie = min(height[j], height[i + j]); l <= j + i; l ++ ){
        //             f[j][j + i] = max(f[j][j + i], f[j][l] + f[l][j + i]);
        //             if (height[l] < bianjie){
        //                 mid += (bianjie - height[l]);
        //             }
        //         }
        //         f[j][j + i] = max(f[j][j + i], mid);
        //     }
        // }

        // return f[0][n - 1];

        //看了一遍题解的代码，发现我是傻子，这太容易想到了吧
        //dp版本
        int n = height.size();
        vector<int> left(n, height[0]);
        for (int i = 1; i < n; i ++ ){
            left[i] = max(left[i - 1], height[i]);
        }

        vector<int> right(n, height[n - 1]);
        for (int i = n - 2; i >= 0; i -- ){
            right[i] = max(right[i + 1], height[i]);
        }

        int res = 0;
        for (int i = 0; i < n; i ++ ){
            res += (min(left[i], right[i]) - height[i]);
        }

        return res;
    }
};