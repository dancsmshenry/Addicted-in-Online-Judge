class Solution {
public:
    int titleToNumber(string columnTitle) {
        unordered_map<char, int> hashmap;
        int res = 0;
        for (int i = 0; i < 26; i ++ ) {
            hashmap[(char)('A' + i)] = i + 1;
        }

        for (int i = 0; i < columnTitle.size(); i ++ ) {
            res *= 26;
            res += hashmap[columnTitle[i]];
        }

        return res;
    }
};