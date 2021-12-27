class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
            其实这个思路挺厉害的
            就像蚂蚁一样，当前的值比target大的话，就往左边走（缩小一下）；比target小的话，就往下走（扩大一下）
            一直这样走，总能走到终点
        */
        if (matrix.size() == 0){
            return false;
        }
        int n = matrix.size(), m = matrix[0].size() - 1;
        int i = 0, j = m;

        while (i < n && j >= 0){
            if (matrix[i][j] == target){
                return true;
            }else if (matrix[i][j] > target){
                j -- ;
            }else{
                i ++ ;
            }
        }

        return false;
    }
};