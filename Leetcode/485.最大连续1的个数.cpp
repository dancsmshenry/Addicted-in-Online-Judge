class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int mid = 0;

        for (auto& num: nums) {
            if (num == 0) {
                mid = 0;
            } else {
                mid ++ ;
                res = max(res, mid);
            }            
        }

        return res;
    }
};