class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quicksort(vector<int>& nums, int left, int right){
        if (left >= right) return ;

        int i = left - 1, j = right + 1;
        // int temp = nums[left];
        int temp = nums[rand() % (right - left + 1) + left];//生成指定范围的随机数
        do{
            do i ++ ; while (nums[i] < temp);
            do j -- ; while (nums[j] > temp);
            if (i < j) swap(nums[i], nums[j]);
        }while (i < j);

        quicksort(nums, left, j);
        quicksort(nums, j + 1, right);
    }
};