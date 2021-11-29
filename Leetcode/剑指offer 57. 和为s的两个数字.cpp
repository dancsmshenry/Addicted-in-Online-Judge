class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        /*经典双指针*/
        while (left < right){
            if (nums[left] + nums[right] == target){
                return {nums[left], nums[right]};
            }else if (nums[left] + nums[right] > target){
                right -- ;
            }else{
                left ++ ;
            }
        }

        return {};
    }
};