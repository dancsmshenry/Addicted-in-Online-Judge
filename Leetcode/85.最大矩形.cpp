class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();   
        int ret = 0;    
        vector<vector<int>> left(m, vector<int>(n, 0));

        /*init*/
        for (int i = 0; i < m; i ++ ){
            for (int j = 0; j < n; j ++ ){
                /*left数组用来存储左边有多少个1的*/
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1;
                }
            }
        }

        /*dp*/
        for (int i = 0; i < m; i ++ ){
            for (int j = 0; j < n; j ++ ){
                if (matrix[i][j] == '0') {
                    continue;
                }
                /*
                    对于每个点，都计算以这个点为右下角顶点的矩形的面积，与ret进行比较，从而取出最大值
                    对于一个矩形，面积是由长和高来决定的
                    对于长，则遍历同一列往上的每一个节点，每往上走一步都记录下当前的最小值
                    （如果记录的不是最小值，那么就无法构成矩形，比如第i行的点的left值是3，第i-1行的点的left值是4，那么就要用3来乘，不能用4）
                    注意，left其实记录的就是每个点往左边的长度（即记录了1的个数）
                    对于宽，则一直往上遍历即可
                */
                int width = left[i][j];
                int area = left[i][j];
                for (int k = i - 1; k >= 0; k -- ){
                    width = min(width, left[k][j]);
                    area = max(area, (i - k + 1) * width);
                }
                ret = max(ret, area);
            }
        }

        return ret;
    }
};