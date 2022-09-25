class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int> nums, int begin) {
        if (begin == nums.size() - 1) {
            ans.push_back(std::move(nums));
        }

        for (int i = begin; i < nums.size(); ++ i) {
            if (i != begin && (nums[i] == nums[begin])) {
                continue;
            }
            swap(nums[i], nums[begin]);
            dfs(nums, begin + 1);
        }
    }
};