class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //这道题值得标记，用队列实现广搜
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//四个方向都走一遍
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int> (m, -1));
        queue<pair<int,int>> Q;
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                if (grid[i][j] == 2) {//发现已经腐烂的橘子
                    Q.push({i, j});//放入队列
                    dis[i][j] = 0;//用来记录橘子是在第几天腐烂的
                } else if (grid[i][j] == 1) {//发现未腐烂的橘子
                    cnt ++ ;//统计橘子数
                }
            }
        }

        while (!Q.empty()) {
            pair<int,int> x = Q.front();//获取未曾遍历的腐烂的橘子
            Q.pop();
            for (auto& dir: dirs) {
                int tx = x.first + dir.first;
                int ty = x.second + dir.second;
                if (tx < 0|| tx >= n || ty < 0|| ty >= m|| ~dis[tx][ty] || !grid[tx][ty]) {
                    continue;
                }//如果有越界或是没有橘子或者是这个橘子已经腐烂，则跳过
                dis[tx][ty] = dis[x.first][x.second] + 1;//传递腐烂
                Q.push({tx, ty});//放入腐烂的橘子
                cnt -- ;//新鲜橘子减一
                ans = dis[tx][ty];//记录天数
            }
        }

        return cnt > 0 ? -1 : ans;
    }
};