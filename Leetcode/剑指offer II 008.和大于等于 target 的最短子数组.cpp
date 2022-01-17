class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //经典双指针(我又看成了之和等于target了....)
        int left = 0, right = 0;
        int mid = 0, result = INT_MAX;

        while (right < nums.size()){
            mid += nums[right];
            while (mid >= target){
                result = min(result, right - left + 1);
                mid -= nums[left];
                left ++ ;
            }
            right ++ ;
        }

        return result == INT_MAX ? 0 : result;
    }
};//和209相同