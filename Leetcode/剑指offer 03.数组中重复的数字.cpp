class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        /*变相实现set*/
        int a[100001];
        memset(a, 0, sizeof(a));
        int res = 0;

        for (int i = 0; i < nums.size(); i ++ ){
            a[nums[i]] ++ ;
            if (a[nums[i]] > 1){
                res = nums[i];
                break;
            }
        }

        return res;
    }
};

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        /*哈希表*/
        int res = 0;
        unordered_map<int, bool> map;

        for(int num: nums) {
            if(map[num]){
                res = num;
                break;
            }
            map[num] = true;
        }
        return res;
    }
};

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        /*sort*/
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i ++ ){
            if (nums[i] == nums[i - 1]){
                return nums[i];
            }
        }

        return 0;
    }
};