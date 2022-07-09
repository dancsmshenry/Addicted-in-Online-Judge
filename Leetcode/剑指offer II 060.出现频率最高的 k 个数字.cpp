bool cmp(pair<int, int> m, pair<int, int> n) {
    return m.second > n.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for (const auto& num: nums) {
            ++ hashmap[num];
        }

        vector<pair<int, int>> temp;
        for (const auto& m: hashmap) {
            temp.push_back({m.first, m.second}); // 这里用不了emplace_back
        }

        sort(temp.begin(), temp.end(), cmp); // 对sort函数理解不够深入

        vector<int> res;
        for (int i = 0; i < k; ++ i) {
            res.push_back(temp[i].first);
        }

        return res;
    }
};