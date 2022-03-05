class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long n1 = abs(n);

        while (n1) {
            if (n1 % 2 == 1) {
                res *= x;
            }
            x *= x;
            n1 /= 2;
        }

        return n >= 0 ? res : 1 / res;
    }
};