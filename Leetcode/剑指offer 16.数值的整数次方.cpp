class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        //剪枝
        if (x == 1){
            return 1;
        }else if (x == -1){
            return (n % 2 == 0) ? 1: -1;
        }

        // 纯暴力
        // for (int n1 = abs(n); n1 > 0; n1 -- ){
        //     result *= x;
        // }

        int n1 = abs(n);
        double x1 = x;

        //快速幂只做了一半，导致出错....
        while (n1 > 0){
            if (n1 % 2 == 1){
                result *= x1;
                n1 -- ;
            }
            x1 *= x1;
            n1 /= 2;
        }

        return n >= 0 ? result : 1 / result;
    }
};