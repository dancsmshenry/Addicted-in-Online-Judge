//dp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, height[0]);
        for (int i = 1; i < n; ++ i) {
            left[i] = max(left[i - 1], height[i]);
        }

        vector<int> right(n, height[n - 1]);
        for (int i = n - 2; i >= 0; -- i) {
            right[i] = max(right[i + 1], height[i]);
        }

        int res{};
        for (int i = 0; i < n; ++ i) {
            res += (min(left[i], right[i]) - height[i]);
        }

        return res;
    }
};

//双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int left = 0, right = n - 1;
        int leftmax = 0, rightmax = 0;

        while (left < right) {
            leftmax = max(leftmax, height[left]);
            rightmax = max(rightmax, height[right]);
            if (height[left] > height[right]) {
                res = res + rightmax - height[right];
                -- right;
            } else {
                res = res + leftmax - height[left];
                ++ left;
            }
        }

        return res;
    }
};