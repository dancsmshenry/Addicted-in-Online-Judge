class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = 0;

        //原始方法
        // for (int i: nums){
        //     if (i == target){
        //         res ++ ;
        //     }else if (i > target){
        //         break;
        //     }
        // }

        //二分版本
        int left = 0, right = nums.size() - 1;

        while (left < right){
            int mid = (left + right) >> 1;
            if (nums[mid] >= target){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        for (int i = right; i < nums.size(); i ++ ){
            if (nums[i] != target){
                break;
            }
            res ++ ;
        }

        return res;
    }
};