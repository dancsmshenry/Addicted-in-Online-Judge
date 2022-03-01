class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> res;
        dfs(candidates, target, res, 0);

        return result;
    }

    void dfs(vector<int>& candidates, int target, vector<int>& res, int begin) {
        if (target == 0) {
            result.push_back(res);
            return ;
        }

        for (int i = begin; i < candidates.size(); ++  i) {
            if (candidates[i] <= target) {
                res.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], res, i);
                res.pop_back();
            } else {
                return ;
            }
        }
    }
};