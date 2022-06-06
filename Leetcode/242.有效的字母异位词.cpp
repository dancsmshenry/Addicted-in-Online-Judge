class Solution {
public:
    bool isAnagram(string s, string t) {
        int flags[26];
        memset(flags, 0, sizeof(flags));

        for (int i = 0; i < s.size(); ++ i) {
            ++ flags[s[i] - 'a'];
        }
        for (int i = 0; i < t.size(); ++ i) {
            -- flags[t[i] - 'a'];
        }

        for (auto flag: flags){
            if (flag < 0 || flag > 0) {
                return false;
            }
        }
        return true;
    }
};