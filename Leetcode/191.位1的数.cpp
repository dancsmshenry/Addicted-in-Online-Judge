class Solution {
public:
    int hammingWeight(uint32_t n) {
        int total = 0;
            
        while (n > 0) {
            if (n & 1 == 1) { // �õ�����1����0
                ++ total;
            }
            n >>= 1;
        }

        return total;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;

        while (n) {
            n &= (n - 1);
            ++ res;
        }

        return res;
    }
};