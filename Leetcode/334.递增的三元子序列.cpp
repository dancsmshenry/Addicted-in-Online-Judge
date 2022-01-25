class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //init
        int n = nums.size();
        int firstmax = nums[n - 1], secondmax = INT_MIN;

        for (int i = n - 2; i >= 0; i -- ) {
            if (firstmax <= nums[i]) {
                /*
                    这里有几点：如果当前的数大于firstmax，那么，一般来说是不用替换
                    因为，此时只要在前面找到一个小于secondmax的数就行了
                    但是，如果找不到secondemax的数字了呢？
                    这时，可以更新（扩大）firstmax，这样后续也会因此扩大secondmax
                    从而变得更有可能找到小于secondmax的数字
                */
                firstmax = nums[i];
            } else if (nums[i] >= secondmax) {
                //道理同上啦
                secondmax = nums[i];
            } else {
                //因为secondmax我设的是INT_MIN，所以一旦比secondmax小的话，那么就符合条件，直接返回true
                return true;
            }
        }

        return false;
    }
};