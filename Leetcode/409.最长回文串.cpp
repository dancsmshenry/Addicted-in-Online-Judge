class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> record(128, 0);

        for (auto& s1: s) {
            ++ record[s1];
        }

        int res{};
        bool flag = false;
        for (auto& r: record) {
            if (r % 2 == 1) {
                flag = true;
                -- res;
            }
            res += r;
        }

        return flag == false ? res : res + 1;
    }
};