// 最普通的方法，利用record记录状态
class Solution {
private:
    vector<vector<int>> res{};
    int n{};
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> record(n, 0);
        vector<int> temp{};
        solve(nums, record, temp);
        return res;
    }

    void solve(vector<int>& nums, vector<int>& record, vector<int>& temp) {
        if (v.size() == n) {
            res.push_back(temp);
            return ;
        }
        for (int i = 0; i < n; ++ i) {
            if (!record[i]) {
                temp.push_back(nums[i]);
                record[i] = true;
                solve(nums, record, temp);
                temp.pop_back();
                record[i] = false;
            }
        }
    }
};

//通过交换来实现回溯，方法一
class Solution {
private:
    int n;
    vector<vector<int>> result;
public:  
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        solve(nums, 0);
        return result;
    }

    void solve(vector<int>& nums, int begin) {
        if (begin == n - 1) {
            result.push_back(nums);
        }

        for (int i = begin; i < n; ++ i ) {
            swap(nums[i], nums[begin]);
            solve(nums, begin + 1);
            swap(nums[i], nums[begin]);
        }
    }
};

//通过交换来实现回溯，方法二
class Solution {
private:
    int n;
    vector<vector<int>> result;
public:    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        solve(nums, 0);
        return result;
    }

    void solve(vector<int> nums, int begin) {
        if (begin == n - 1) {
            result.push_back(nums);
            return ;
        }

        for (int i = begin; i < n; ++ i ) {
            swap(nums[i], nums[begin]);
            solve(nums, begin + 1);
        }
    }
};