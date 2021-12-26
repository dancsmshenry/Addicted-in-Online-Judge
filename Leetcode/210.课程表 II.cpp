class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //感觉这类题是模板题了，可以通过刻意练习来学会的.....拓扑排序
        vector<vector<int>> map(numCourses);
        vector<int> record(numCourses, 0);

        for (const auto& i:prerequisites){
            record[i[0]] ++ ;
            map[i[1]].push_back(i[0]);
        }

        queue<int> q1;
        for (int i = 0; i < numCourses; i ++ ){
            if (record[i] == 0){
                q1.push(i);
            }
        }

        vector<int> result{};
        while (q1.size()){
            int number = q1.front();
            result.push_back(number);
            q1.pop();
            
            for (auto& i: map[number]){
                record[i] -- ;
                if (record[i] == 0){
                    q1.push(i);
                }
            }
        }

        return result.size() == numCourses ? result : vector<int>{};
    }
};