class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) {//被除数为0，直接返回0
            return 0;
        }
        if(divisor == 1) {//除数为1，直接返回原数
            return dividend;
        }
        if(divisor == -1) {//除数为-1，就要判断边界
            if(dividend > INT_MIN) {
                return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
            } else {
                return INT_MAX;// 是最小的那个，那就返回最大的整数啦
            }
        }

        long a = dividend;
        long b = divisor;
        int sign = 1; //去除正负号
        if((a > 0 && b < 0) || (a < 0 && b > 0)) {
            sign = -1;
        }
        long res = div(abs(a), abs(b));
        if(sign == 1) {//防溢出
            return res > INT_MAX ? INT_MAX : res;
        }
        return -res;
    }

    int div(long a, long b) {
        long count = 1, res = 0;
        
        while (a >= b) {
            long tb = b;
            while((tb * 2) <= a) {
                count += count; // 最小解翻倍
                tb += tb; // 当前测试的值也翻倍
            }
            res += count;
            count = 1;
            a -= tb;
        }

        return res;
    }
};