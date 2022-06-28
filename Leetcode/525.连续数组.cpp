class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int maxn = 0;
        int n = nums.size();

        for (int i = 0, record = 0; i < n; ++ i) {
            record += (nums[i] == 0) ? -1: 1;
            if (record == 0) {
                maxn = i + 1;
                continue;
            }
            if (hashmap.count(record)) {
                maxn = max(maxn, i - hashmap[record]);
            } else {
                hashmap[record] = i;
            }
        }

        return maxn;
    }
};