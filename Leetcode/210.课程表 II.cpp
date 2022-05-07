class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> course(numCourses, vector<int>{});
        vector<int> record(numCourses, 0);

        for (auto&& prerequisite: prerequisites) {
            course[prerequisite[1]].push_back(prerequisite[0]);
            ++ record[prerequisite[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++ i) {
            if (record[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res{};
        while (!q.empty()) {
            int mid = q.front();
            q.pop();
            res.push_back(mid);

            for (auto&& number: course[mid]) {
                -- record[number];
                if (record[number] == 0) {
                    q.push(number);
                }
            }
        }

        return res.size() == numCourses ? res : vector<int>{};
    }
};