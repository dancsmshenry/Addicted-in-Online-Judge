class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count{};
        unordered_map<int, int> record{};
        record[0] = 1;  //  细节：当只有一个数求余后得到0，就要给它补上一个1

        for (auto& num: nums) {
            count += num;
            ++ record[(count % k + k) % k];
        }

        int res{};
        for (auto& r: record) {
            res += r.second * (r.second - 1) / 2;
        }

        return res;
    }
};