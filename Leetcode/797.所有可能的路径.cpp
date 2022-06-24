class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp{0};
        dfs(0, graph, temp);
        return result;
    }

    void dfs(int index, vector<vector<int>>& graph, vector<int>& temp) {
        if (temp.size() > 0 && temp.back() == graph.size() - 1) {
            result.push_back(temp);
            return ;
        }
        for (int i = 0; i < graph[index].size(); ++ i) {
            temp.push_back(graph[index][i]);
            dfs(graph[index][i], graph, temp);
            temp.pop_back();
        }
    }
};