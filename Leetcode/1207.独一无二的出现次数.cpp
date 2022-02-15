class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hashmap;
        unordered_set<int> hashset;

        for (auto& num: arr) {
            hashmap[num] ++ ;
        }

        for (auto& h: hashmap) {
            hashset.insert(h.second);
        }

        return hashset.size() == hashmap.size();
    }
};