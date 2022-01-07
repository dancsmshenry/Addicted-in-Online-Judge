class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //经典回溯算法
        vector<int> f{};
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, f, 0);
        return res;
    }

    void solve(vector<int>& candidates, int target, vector<int>& mid, int begin){
        if (target == 0){
            res.push_back(mid);
            return ;
        }
        for (int i = begin; i < candidates.size(); i ++ ){
            if (i > begin && candidates[i - 1] == candidates[i]) continue;
            if (target >= candidates[i]){
                mid.push_back(candidates[i]);
                solve(candidates, target - candidates[i], mid, i + 1);
                mid.pop_back();
            }
        }
    }
};