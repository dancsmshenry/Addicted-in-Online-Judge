class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //n&1得到最后一位
        uint32_t res = 0;
        int i = 0;

        while (n > 0 || i < 32){
            i ++ ;
            uint32_t temp = n & 1;
            n >>= 1;
            res <<= 1;
            res |= temp;
        }

        return res;
    }
};