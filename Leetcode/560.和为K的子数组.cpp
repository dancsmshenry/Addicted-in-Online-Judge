class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int res = 0;
        unordered_map<int, int> hashmap;
        hashmap[0] ++ ;

        for (auto& num: nums) {
            count += num;
            if (hashmap.count(count - k)) {
                res += hashmap[count - k];
            }
            hashmap[count] ++ ;
        }

        return res;
    }
};