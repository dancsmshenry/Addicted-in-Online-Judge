class Solution{
public:
    bool canFinish(int numCourses, const vector<vector<int>> &prerequisites) {
        /*
            拓扑排序：
            每门课都有它的先修课程，依此就可以画出一幅结点相连的拓扑图
            大概思路就是，先找到不依赖其他先修课的课，把它学习了以后，减去以这门课为先修课的课程的入度，检查此时入度为0的课
            有的话就把他放入队列中
            同时记录这门课已经学完了，学习总数+1
            然后再从队列中拿一个点出来，继续这样的操作
            直到队列为空
            最后返回学习的课程的总数是否等于课程的总数

            做题套路：对于每个点来说，记录它又多少个先修课（方便后续当它为0的时候把它放入队列），用一个一维数组
            同时，记录以这门课为先修课的课有哪些（方便后续遍历，减去它的度数），用一个二维数组
        */
        vector<vector<int>> edges(numCourses); //边，记录以课程i为先修课的课程
        vector<int> indegree(numCourses);      //入度，即课程i有几门先修课
        
        //init
        for (auto &p : prerequisites) {
            edges[p[1]].push_back(p[0]);
            ++ indegree[p[0]];
        }

        //用一个队列来记录入度为0的课程
        queue<int> q;
        for (int i = 0; i < numCourses; ++ i) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        int vCount = 0; //正常参与拓扑排序的课程数
        while (q.size()) {
            auto v = q.front(); //取出顶点v
            q.pop();
            ++ vCount;

            for (auto i : edges[v]) {
                -- indegree[i];//有以v为先修的入度都减1
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        return vCount == numCourses;//最后查看参与排序的课程数是否等于总课程数
    }
};