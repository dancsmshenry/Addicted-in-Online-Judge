class Solution {
private:
    vector<vector<int>> res{};
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp{};
        sort(candidates.begin(), candidates.end());
        dfs(candidates, temp, target, 0);
        return res;
    }

    void dfs(vector<int>& candidates, vector<int>& temp, int target, int begin) {
        if (target == 0) {
            res.push_back(temp);
            return ;
        }

        for (int i = begin; i < candidates.size(); ++ i) {
            if (i != begin && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] <= target) {
                temp.push_back(candidates[i]);
                dfs(candidates, temp, target - candidates[i], i + 1);
                temp.pop_back();
            }
        }
    }
};