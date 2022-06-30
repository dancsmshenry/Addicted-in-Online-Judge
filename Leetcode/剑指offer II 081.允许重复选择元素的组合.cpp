class Solution {
private:
    vector<vector<int>> res;
    int n{};
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        n = candidates.size();
        dfs(candidates, target, 0, temp);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int index, vector<int>& temp) {
        if (target == 0) {
            res.push_back(temp);
            return ;
        }
        
        for (int i = index; i < n; ++ i) {
            if (target >= candidates[i]) {
                temp.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i, temp);
                temp.pop_back();
            } else {
                return ;
            }
        }
    }
};