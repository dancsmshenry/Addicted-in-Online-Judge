class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /**
            思路：
            先把哈希表全部设为空
            然后对当前的nums数组进行一次遍历，用来查找target-nums[i]
            如果没找到，就把当前的数字和下标插入到哈希表当中
            如果找到了，就返回当前数字的下标和target-nums[i]的下标
        **/

        unordered_map<int, int> hashmap;
        int n = nums.size();

        for (int i = 0; i < n; ++ i) {
            if (hashmap.count(target - nums[i])) {
                return {hashmap[target - nums[i]], i};
            } else {
                hashmap[nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};