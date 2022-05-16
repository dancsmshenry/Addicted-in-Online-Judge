class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> hashset;
        vector<int> result;

        for (int& i: nums1) {
            hashset.insert(i);
        }

        for (int& i: nums2) {
            if (hashset.count(i)) {
                res.insert(i);
            }
        }

        for (const int& i: res) {
            result.push_back(i);
        }
        return result;
    }
 };