class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, nums[0]);
        for (int i = 1; i < n; ++ i) {
            arr[i] = arr[i - 1] + nums[i];
        }

        int prev = 0;
        for (int i = 0; i < n; ++ i) {
            if (prev == arr[n - 1] - arr[i]) {
                return i;
            }
            prev += nums[i];
        }
        
        return -1;
    }
};