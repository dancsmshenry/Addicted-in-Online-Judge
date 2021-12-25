class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count_0 = 0;

        for(int i = 0; i < 4; i ++ ){
            if(nums[i] == 0){
                //记录0的牌的次数
                count_0++;
            }else if(nums[i] == nums[i + 1]){
                //出现了重复的牌，直接false
                return false;
            }
        }

        return nums[4] - nums[count_0] < 5;
    }
};