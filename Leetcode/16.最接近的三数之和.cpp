class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int result = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i ++ ){
            int left = i + 1, right = n - 1;
            while (left < right){
                int mid = nums[i] + nums[right] + nums[left];
                if (target > mid){
                    left ++ ;
                }else{
                    right -- ;
                }
                if (abs(mid - target) < abs(result - target)) result = mid;
            }
        }

        return result;
    }
};
//这里的优化的话，可以往去重上面继续优化