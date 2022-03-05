class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int mid = numbers[left] + numbers[right];
            if (mid > target) {
                right -- ;
            } else if (mid < target) {
                left ++ ;
            } else {
                return {left + 1, right + 1};
            }
        }

        return {-1, -1};
    }
};