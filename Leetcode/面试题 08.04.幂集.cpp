    class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), length = 1;
        vector<vector<int>> ans;

        for (int i = 0; i < n; i ++ ){
            length *= 2;
        }

        for (int i = 0; i < length; i ++ ){
            int l1 = i, l2, l3 = 0;
            vector<int> len;
            while (l1){
                l2 = l1 % 2;
                if (l2) len.push_back(nums[l3]);
                l3 ++ ;
                l1 /= 2;
            }
            ans.push_back(len);
        }

        return ans;
    }
};

class Solution {
private:
    vector<vector<int>> res{};
    int n{};
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp{};
        n = nums.size();
        dfs(nums, temp, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& temp, int begin) {
        res.push_back(temp);
        if (begin == n) {
            return ;
        }

        for (int i = begin; i < n; ++ i) {
            temp.push_back(nums[i]);
            dfs(nums, temp, i + 1);
            temp.pop_back();
        }
    }
};