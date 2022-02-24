class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0, n = nums.size();

        for (int i = 1; i < n; ++ i) {
            if (nums[i - 1] > nums[i]) {
                count ++ ;
                if (count > 1) {
                    return false;
                }
                if (i > 1 && nums[i] < nums[i - 2]) {
                    nums[i] = nums[i - 1];
                }
            }
        }

        return true;
    }
};