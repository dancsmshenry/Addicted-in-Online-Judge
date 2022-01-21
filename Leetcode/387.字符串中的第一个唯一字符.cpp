class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashmap;
        for (auto s1: s){
            hashmap[s1] ++ ;
        }

        for (int i = 0; i < s.size(); i ++ ){
            if (hashmap[s[i]] == 1){
                return i;
            }
        }

        return -1;
    }
};