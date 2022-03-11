class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1;
        int mid = 1;
        int n = nums.size();

        for (int i = 1; i < n; ++ i) {
            if (nums[i] > nums[i - 1]) {
                mid ++ ;
                res = max(res, mid);
            } else {
                mid = 1;
            }
        }

        return res;
    }
};