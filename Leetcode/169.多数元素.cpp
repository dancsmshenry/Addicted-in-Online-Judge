class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
            
        for (long i = 0, two = 1; i < 32; i ++ ) {
            int number = 0;
            for (auto& num: nums) {
                number += (num >> i) & 1;
            }
            if (number > n / 2) {
                result += two;
            }
            two *= 2;
        }

        return result;
    }
};

//摩尔投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int target = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++ i) {
            if (count == 0) {
                target = nums[i];
                count = 1;
            } else {
                if (target == nums[i]) {
                    count ++ ;
                } else {
                    count -- ;
                }
            }
        }

        return target;
    }
};