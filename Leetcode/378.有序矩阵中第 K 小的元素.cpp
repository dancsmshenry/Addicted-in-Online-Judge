class Solution {
public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n){
        int i = n - 1;
        int j = 0;
        int num = 0;
        while (i >= 0 && j < n){
            if (matrix[i][j] <= mid){
                num += i + 1;
                j ++ ;
            }else{
                i -- ;
            }
        }
        return num >= k;
    }

    /*
        现在matrix[0][0]和matrix[n - 1][n - 1]之间找一个数mid
        然后从左下方开始走，
        如果当前的数比mid大的话，就往上走；否则就往右走
        （如果往右走，就证明该数在的这一列都小于mid，所以num++,这里num是用来统计mid大于的数字的）
        最后，比较num和k的大小，
        如果num>k，就把right的范围收上来，否则就把left的范围收上来
        
        这里的一个思想其实是，我在left和right之间找一个数（mid），看看在这个矩阵里面比这个数小的数的数目有多少
        如果大于等于k的话，那我们要找的第k小的数就是在left和mid之间，所以就要调整right的位置
        否则就是在mid和right之间，就要调整left的位置
        所以check函数的作用就是判断num和k的关系，从而调整left和right的位置
    */

    int kthSmallest(vector<vector<int>>& matrix, int k){
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(matrix, mid, k, n)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
};