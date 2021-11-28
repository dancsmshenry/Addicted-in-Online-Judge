class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*哈希表会快一点吧*/
        unordered_map<int, int> count;
        int n = nums.size();

        for (int i: nums){
            count[i] ++ ;
            if (count[i] * 2 >= n){
                return i;
            }
        }

        return 0;
    }
};