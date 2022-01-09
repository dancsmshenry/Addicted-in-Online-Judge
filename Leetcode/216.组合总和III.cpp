class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum3(int k, int n){
        //经典套路，就不多说了吧
        vector<int> mid;
        solve(k, n, mid, 1);
        return res;
    }

    void solve(int k, int n, vector<int>& mid, int begin){
        for (int i = begin; i < 10; i ++ ){
            if (n > i && mid.size() + 1 <= k){
                mid.push_back(i);
                solve(k, n - i, mid, i + 1);
                mid.pop_back();
            }else if (n == i && mid.size() + 1 == k){
                mid.push_back(i);
                res.push_back(mid);
                mid.pop_back();
            }else break;
        }
    }
};