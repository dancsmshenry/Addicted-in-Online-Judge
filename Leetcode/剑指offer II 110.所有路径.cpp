class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp{0};
        dfs(graph, 0, temp);
        return res;
    }

    void dfs(vector<vector<int>>& graph, int index, vector<int>& temp) {
        if (temp.back() == graph.size() - 1) {
            res.push_back(temp);
            return ;
        }

        for (auto&& number: graph[index]) {
            temp.push_back(number);
            dfs(graph, number, temp);
            temp.pop_back();
        }
    }
};