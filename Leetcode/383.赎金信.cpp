class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // unordered_map<char, int> map1, map2;
        int map1[128], map2[128];
        memset(map1, 0, sizeof(map1));
        memset(map2, 0, sizeof(map2));

        for (auto&& s: ransomNote) {
            ++ map1[s];
        }

        for (auto&& s: magazine) {
            ++ map2[s];
        }

        for (auto&& s: ransomNote) {
            // if (!map2.count(s) || map1[s] > map2[s]) {
            if (map2[s] == 0 || map1[s] > map2[s]) { 
                return false;
            }
        }

        return true;
    }
};