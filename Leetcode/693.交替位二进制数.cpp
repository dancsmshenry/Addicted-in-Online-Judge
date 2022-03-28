class Solution {
public:
    bool hasAlternatingBits(int n) {
        int record = -1;

        while (n) {
            int mid = n & 1;
            if (mid != record) {
                record = mid;
            } else {
                return false;
            }
            n >>= 1;
        }

        return true;
    }
};

class Solution {
public:
    bool hasAlternatingBits(int n) {
        // 如 010101 右移一位得到 001010
        // 二者异或之后得到011111  (这一步是关键,只有交替出现01，异或后才能得到结果0111111...11)
        // 为了判断 异或后的结果是否满足(0111111...11)类型的结果
        // 可以用如下方法，比如
        // 011111 加上1 为100000
        // 011111 与 100000按位相与 结果为000000 ， 也就是0;
        unsigned int m = n ^ (n >> 1);

        return ((m & (m + 1)) == 0);
    }
};