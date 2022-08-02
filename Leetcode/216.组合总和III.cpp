class Solution {
private:
    int k{};
    vector<vector<int>> res{};
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp{};
        this -> k = k;
        dfs(temp, 1, n);
        return res;
    }

    void dfs(vector<int>& temp, int begin, int target) {
        if (k < temp.size()) {
            return ;
        }
        if (target == 0 && temp.size() == k) {
            res.push_back(temp);
        }
        

        for (int i = begin; i < 10; ++ i) {
            if (i > target) {
                return ;
            }
            temp.push_back(i);
            dfs(temp, i + 1, target - i);
            temp.pop_back();
        }
    }
};