class Solution {
private:
    vector<vector<int>> res{};
    int n{};
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp{};
        n = candidates.size();
        dfs(candidates, temp, target, 0);
        return res;
    }

    void dfs(vector<int>& candidates, vector<int>& temp, int target, int begin) {
        if (target == 0) {
            res.push_back(temp);
            return ;
        }
        for (int i = begin; i < n; ++ i) {
            if (target < candidates[i]) {
                continue;
            }
            temp.push_back(candidates[i]);
            dfs(candidates, temp, target - candidates[i], i);
            temp.pop_back();
        }
    }
};