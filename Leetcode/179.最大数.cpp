class Solution {
public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            //可以mark一下，这是逐层比较最高位的一种写法，非常的巧妙
            //因为，之前，我都是认为要把数字逐个逐个的拿下来，然后再进行比较，可这里完全不用啊
            long sx = 10, sy = 10;
            while (sx <= x) {
                sx *= 10;
            }
            while (sy <= y) {
                sy *= 10;
            }
            return sy * x + y > sx * y + x;
        });

        if (nums[0] == 0) {
            return "0";
        }

        string res;

        for (auto &x : nums) {
            res += to_string(x);
        }

        return res;
    }
};