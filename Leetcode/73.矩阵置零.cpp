class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {//O(m+n)的做法
        vector<int> f1(matrix.size(), 0);
        vector<int> f2(matrix[0].size(), 0);

        //init
        for (int i = 0; i < matrix.size(); i ++ ){
            for (int j = 0; j < matrix[0].size(); j ++ ){
                if (matrix[i][j] == 0){
                    f1[i] = 1;
                    f2[j] = 1;
                }
            }
        }

        //main
        for (int i = 0; i < matrix.size(); i ++ ){
            for (int j = 0; j < matrix[0].size(); j ++ ){
                if (f1[i] == 1 || f2[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

//O(n)的写法，但是时间上没优化好....
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int flag1 = 0, flag2 = 0;//用flag1和flag2来表示行列中是否有0，方便后续处理
        for (int i = 0; i < matrix.size(); i ++ ){
            for (int j = 0; j < matrix[0].size(); j ++ ){
                if (matrix[i][j] == 0){
                    flag1 = (i == 0) ? ++ flag1 : flag1;
                    flag2 = (j == 0) ? ++ flag2 : flag2;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i ++ ){
            for (int j = 1; j < matrix[0].size(); j ++ ){
                if (matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if (flag1 != 0){
            for (int i = 0; i < matrix[0].size(); i ++ ){
                matrix[0][i] = 0;
            }
        }
        if (flag2 != 0){
            for (int i = 0; i < matrix.size(); i ++ ){
                matrix[i][0] = 0;
            }
        }
    }
};

//更加官方的O(n)解法
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix){
        int flag = 0;
        for (int i = 0; i < matrix.size(); i ++ ){
            if (matrix[i][0] == 0){//如果最左边的一列有零的话，就把flag设为1
                flag = 1;
            }
            for (int j = 1; j < matrix[0].size(); j ++ ){
                if (matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;//如果当前点为0的话，就把它最上面的一行和最左边的一列变为0
                }
            }
        }

        for (int i = matrix.size() - 1; i >= 0; i -- ){//这里是必须从下往上走的，因为从上往下走的话，如果第一行因为(0,0)全部变为了0，那么，以后的数字就都变为0了
            for (int j = 1; j < matrix[0].size(); j ++ ){//从1开始，是因为最左列是用来参考的，后面再判断的
                if (matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if (flag == 1){
                matrix[i][0] = 0;
            }
        }
    }
};