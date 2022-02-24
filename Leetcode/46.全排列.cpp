class Solution {
public:
    vector<vector<int>> res;
    int n;

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        bool flag[n];
        memset(flag, false ,sizeof(flag));

        vector<int> v;
        solve(nums, flag, v);
        return res;
    }

    void solve(vector<int>& nums, bool flag[], vector<int>& v) {
        if (v.size() == n) {
            res.push_back(v);
            return ;
        }
        for (int i = 0; i < n; i ++ ) {
            if (!flag[i]) {
                v.push_back(nums[i]);
                flag[i] = true;
                solve(nums, flag, v);
                v.pop_back();
                flag[i] = false;
            }
        }
    }
};

//通过交换来实现回溯，非常的聪明
class Solution {
public:
    int n;
    vector<vector<int>> result;
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        solve(nums, 0);
        return result;
    }

    void solve(vector<int>& nums, int begin) {
        if (n == begin) {//这里n和n-1都可以
            result.push_back(nums);
        }

        for (int i = begin; i < n; ++ i ) {
            swap(nums[i], nums[begin]);
            solve(nums, begin + 1);
            swap(nums[i], nums[begin]);
        }
    }
};

//另一种做法，思路同上
class Solution {
public:
    int n;
    vector<vector<int>> result;
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        solve(nums, 0);
        return result;
    }

    void solve(vector<int> nums, int begin) {
        if (n - 1 == begin) {//这里n和n-1也是一样的
            result.push_back(nums);
            return ;
        }

        for (int i = begin; i < n; ++ i ) {
            swap(nums[i], nums[begin]);
            solve(nums, begin + 1);
        }
    }
};