class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<long, int> hashmap;
        int res = 0;

        for (auto& num1: nums1){
            for (auto& num2: nums2){
                hashmap[num1 + num2] ++ ;
            }
        }

        for (auto& num3: nums3){
            for (auto& num4: nums4){
                if (hashmap.count(0 - num3 - num4)){
                    res += hashmap[0 - num3 - num4];
                }
            }
        }

        return res;
    }
};