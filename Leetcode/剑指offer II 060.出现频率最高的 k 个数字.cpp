class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for (const auto& num: nums) {
            ++ hashmap[num];
        }

        vector<pair<int, int>> temp;
        for (const auto& m: hashmap) {
            temp.push_back({m.first, m.second}); // �����ò���emplace_back
        }

        sort(temp.begin(), temp.end(), [](pair<int, int> m, pair<int, int> n) {
            return m.second > n.second;
        }); // ��sort������ⲻ������

        vector<int> res;
        for (int i = 0; i < k; ++ i) {
            res.push_back(temp[i].first);
        }

        return res;
    }
};