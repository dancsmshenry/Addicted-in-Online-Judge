class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < 32; i ++ ) {
            int count = 0;
            for (auto& num: nums) {
                count += (num >> i) & 1;
            }
            res += (count % 3) << i;
        }

        return res;
    }
};
//题述：其他数字出现三的倍数次，找出没有出现三的倍数次的那个数(换一下题面，还是一样的题目)