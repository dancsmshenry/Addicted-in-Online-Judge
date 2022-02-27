class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n; ++ i ) {
            if (i > 0 && nums[i] == nums[i - 1]) {//去重
                continue;
            }
            if (nums[i] > 0) {//因为数组已经排好序了，所以，如果当前的数已经大于0了，后面的数加起来也不会等于0的
                break;
            }
            int left = i + 1, right = n - 1;
            while (left < right) {//注意不要等号
                int temp = nums[left] + nums[right] + nums[i];
                if (temp == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    do left ++ ; while (nums[left] == nums[left - 1] && left < right);//去重
                    do right -- ; while (nums[right] == nums[right + 1] && right > left);//去重
                } else if (temp > 0) {
                    do right -- ; while (nums[right] == nums[right + 1] && right > left);//去重
                } else {
                    do left ++ ; while (nums[left] == nums[left - 1] && left < right);//去重
                }
            }
        }

        return res;
    }
};