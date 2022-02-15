class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;

        for (auto& num: nums) {
            ret ^= num;
        }

        int div = ret & (-ret);
        int a = 0, b = 0;
        for (auto& num: nums) {
            if (div & num) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return vector<int>{a, b};
    }
};