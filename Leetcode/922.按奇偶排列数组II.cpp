class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int slow = 0, fast = 1;
        int n = nums.size();
        
        while (slow < n && fast < n) {
            while (slow < n && nums[slow] % 2 == 0) {
                slow += 2;
            }
            while (fast < n && nums[fast] % 2 == 1) {
                fast += 2;
            }
            if (slow < n && fast < n) {
                swap(nums[slow], nums[fast]);
            }
        }

        return nums;
    }
};