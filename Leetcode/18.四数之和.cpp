class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //排序+双循环+双指针
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int k = 0; k < nums.size(); ++ k) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;//去重

            for (int i = k + 1; i < nums.size(); ++ i) {
                if (i > k + 1 && nums[i] == nums[i - 1]) continue;//去重

                int left = i + 1, right = nums.size() - 1;
                while (right > left) {
                    // 使用long扩大类型（注意不要把值加完以后才扩大类型，因为在加的过程中就会超出范围！）
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        //大于target的情况，right右移
                        -- right;
                    }else if ((long)nums[k] + nums[i]  + nums[left] + nums[right]< target) {
                        //小于target的情况，left左移
                        ++ left;
                    }else{
                        result.push_back({nums[k], nums[i], nums[left], nums[right]});
                        // 去重
                        // 这里while中条件的先后顺序很重要，反过来的话会导致越界
                        while (right > left && nums[right] == nums[right - 1]) -- right;
                        while (right > left && nums[left] == nums[left + 1]) ++ left;
                        // 注意，这里找到答案以后，两个指针要同时移动
                        -- right;
                        ++ left;
                    }
                }
            }
        }

        return result;
    }
};