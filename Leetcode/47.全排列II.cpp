// 最普通的方法，利用record记录状态
class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> record(22, 0);

        for (int i = 0; i < nums.size(); ++ i) {
            ++ record[nums[i] + 10];
        }
        
        vector<int> temp{};
        solve(record, temp);
        return res;
    }

    void solve(vector<int>& record, vector<int>& temp) {
        if (temp.size() == record.size()) {
            res.push_back(temp);
            return ;
        }

        for (int i = 0; i < record.size(); ++ i) {
            if (record[i] > 0) {
                temp.push_back(i - 10);
                -- record[i];
                solve(record, temp);
                ++ record[i];
                temp.pop_back();
            }
        }
    }
};

class Solution {
public:
    int n;
    vector<vector<int>> result;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        solve(nums, 0);

        return result;
    }

    void solve(vector<int> nums, int begin) {
        if (begin == n) {
            result.push_back(nums);
            return ;
        }

        for (int i = begin; i < n; ++ i) {
            if (i != begin && nums[i] == nums[begin]) {
                continue;
            }
            swap(nums[begin], nums[i]);
            solve(nums, begin + 1);    
        }
    }
};