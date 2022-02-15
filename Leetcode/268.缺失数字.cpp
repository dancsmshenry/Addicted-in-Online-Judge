class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for (auto& num: nums) {
            total += num;
        }

        return n * (n + 1) / 2 - total;
    }
};