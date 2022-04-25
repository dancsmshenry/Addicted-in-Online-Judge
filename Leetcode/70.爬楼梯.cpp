class Solution {
public:
    int climbStairs(int n) {
        int first = 1, second = 1;

        for (int i = 2; i <= n; ++ i) {
            int temp = second;
            second = second + first;
            first = temp;
        }

        return second;
    }
};