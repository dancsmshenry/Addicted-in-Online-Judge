class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> hashmap;
        for (auto& num: nums) {
            hashmap[num] ++ ;
        }
        while (hashmap.count(original)) {
            original *= 2;
        }

        return original;
    }
};