class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> result = solve(n);
        int j = n - 1;
        while (j -- > 0) result.pop_back();
        return result;
    }

    vector<double> solve(int n) {
        /*思路：上一次遍历得到的结果，下一次再接着乘上去，以此类推*/
        vector<double> f(6, 1.0/6.0);
        if (n == 1){
            return f;
        }
        
        vector<double> f1 = solve(n - 1);
        vector<double> result(n * 6, 0);

        for (int i = 0; i < f1.size(); i ++ ){
            for (int j = 0; j < 6; j ++ ){
                result[i+j] += f1[i] * f[j];
            }
        }

        return result;
    }
};