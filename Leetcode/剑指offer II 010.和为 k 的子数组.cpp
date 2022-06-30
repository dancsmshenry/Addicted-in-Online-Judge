class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        int n = nums.size();
        int res = 0;
        ++ hashmap[0];

        for (int i = 0, count = 0; i < n; ++ i) {
            count += nums[i];
            if (hashmap.count(count - k)) {
                res += hashmap[count - k];
            }
            ++ hashmap[count];
        }

        return res;
    }
};