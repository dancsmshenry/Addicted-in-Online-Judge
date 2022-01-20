class Solution {
public:
    int movingCount(int m, int n, int k) {
        /*记录出问题瞬间：没有用数组记录状态，导致无限递归，爆出bug了....*/
        vector<vector<int>> count(m, vector<int> (n, 0));
        return solve(count, 0, 0, m, n, k);
    }

    int calculate(int number1, int number2){
        int res = 0;
        while (number1){
            res += (number1 % 10);
            number1 /= 10;
        }
        while (number2){
            res += (number2 % 10);
            number2 /= 10; 
        }
        return res;
    }

    int solve(vector<vector<int>>& count, int i, int j, int m, int n, int k){
        if (i >= m || j >= n || calculate(i, j) > k || count[i][j]){
            return 0;
        }
        
        count[i][j] = 1;

        return 1 + solve(count, i + 1, j, m, n, k) + solve(count, i, j + 1, m, n, k);//这里优化了一下，只往右或下走
    }
};