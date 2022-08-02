class Solution {
private:
    vector<vector<int>> res;
    int k{};
    int n{};
public:
    vector<vector<int>> combine(int n, int k) {
        this -> k = k;
        this -> n = n;
        vector<int> flag(n + 1, 0);
        vector<int> temp{};
        dfs(1, flag, temp);
        return res;
    }

    void dfs(int begin, vector<int>& flag, vector<int>& temp) {
        if (k - temp.size() > n - begin + 1) {
            return ;
        }
        if (temp.size() == k) {
            res.push_back(temp);
            return ;
        }
        for (int i = begin; i <= n; ++ i) {
            if (!flag[i]) {
                temp.push_back(i);
                flag[i] = 1;
                dfs(i + 1, flag, temp);
                flag[i] = 0;
                temp.pop_back();
            }
        }
    }
};

class Solution {
private:
    vector<vector<int>> res{};
    int n{};
    int k{};
public:
    vector<vector<int>> combine(int n, int k) {
        this -> n = n;
        this -> k = k;
        vector<int> temp{};
        dfs(temp, 1);
        return res;
    }

    void dfs(vector<int>& temp, int begin) {
        if (k - temp.size() > n - begin + 1) {
            return ;
        }
        if (temp.size() == k) {
            res.push_back(temp);
            return ;
        }
        for (int i = begin; i <= n; ++ i) {
            temp.push_back(i);
            dfs(temp, i + 1);
            temp.pop_back();
        }
    }
};