class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        
        for (auto& s1: s) {
            res ^= s1;
        }

        for (auto& t1: t) {
            res ^= t1;
        }

        return res;
    }
};