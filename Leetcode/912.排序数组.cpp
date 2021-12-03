class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quicksort(vector<int>& nums, int left, int right){
        if (left >= right){
            return ;
        }

        int i = rand() % (right - left + 1) + left;/*随机取数才不会被卡时间.....*/
        int mid = nums[i], l = left - 1, r = right + 1;
        swap(nums[i], nums[left]);
        while(r > l){
            do l ++ ; while(nums[l] < mid);
            do r -- ; while(nums[r] > mid);
            if (r > l){
                swap(nums[l], nums[r]);
            }
        }

        quicksort(nums, left, r);
        quicksort(nums, r + 1, right);
    }
};