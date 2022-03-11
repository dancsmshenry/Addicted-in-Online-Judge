class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //看到的一种非常巧妙的解法
        string res = "";
        int n = strs.size();

        for (int i = 0; i < strs[0].size(); ++ i) {
            char mid = strs[0][i];
            for (int j = 1; j < n; ++ j) {
                if (strs[j][i] != mid) {
                    return res;
                }
            }
            res += mid;
        }

        return res;
    }
};