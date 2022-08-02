class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {   
        vector<int> mid;
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < (1 << n); ++ i) {
            int number = i;
            mid.clear();
            
            for (int j = 0; j < n; ++ j) {
                if (number % 2 == 1) {
                    mid.push_back(nums[j]);
                }
                number /= 2;     
            }

            res.push_back(mid);
        }

        return res;
    }
};

class Solution {
private:
    vector<vector<int>> res{};
    int n{};
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> temp{};
        dfs(nums, temp, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& temp, int begin) {
        res.push_back(temp);

        for (int i = begin; i < n; ++ i) {
            temp.push_back(nums[i]);
            dfs(nums, temp, i + 1);
            temp.pop_back();
        }
    }
};