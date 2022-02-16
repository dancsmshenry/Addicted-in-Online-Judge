class Solution {
public:
    double myPow(double x, int n) {
        long long n1 = n;
        return n1 < 0 ? 1 / poww(x, -n1) :  poww(x, n1);
    }

    double poww(double x, long long n1) {//注意-2的31次方.....
        double res = 1;

        while (n1 > 0) {
            if (n1 % 2 == 1) {
                res *= x;
            }
            n1 /= 2;
            x *= x;
        }

        return res;
    }
};