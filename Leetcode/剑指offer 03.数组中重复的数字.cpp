/* hashmap */
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> hashmap;

        for (auto& num: nums) {
            if (hashmap.count(num)) {
                return num;
            }
            hashmap[num] ++ ;
        }

        return 0;
    }
};

/* 原地哈希 */
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0, n = nums.size();

        while (i < n) {
            if (nums[i] == i) {//如果当前的数字是在自己的位置上，就i++
                i ++ ;
                continue;
            }
            if (nums[nums[i]] == nums[i]) {//如果当前的数字和对于位置的数字相同，就代表这个数字重复了，return
                return nums[i];
            }
            swap(nums[nums[i]], nums[i]);//表示当前数字不再对应下标的位置，交换
        }

        return 0;
    }
};