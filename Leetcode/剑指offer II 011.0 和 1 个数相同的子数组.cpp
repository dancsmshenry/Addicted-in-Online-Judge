class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //  一开始想到的是dp，用双循环解决，但是时间复杂度太高了
        //  后面看了看标签，瞬间理解了
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

//  更好的做法
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < n; ++ i) {
            if (prev == total - (prev + nums[i])) {
                return i;
            }
            prev += nums[i];
        }

        return -1;
    }
};