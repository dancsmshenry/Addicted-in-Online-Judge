class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int res = 0;
        int fast = 1;
        unordered_set<char> hashmap;
        
        for (int i = 0; i < n; ++ i) {
            if (i == 0) {
                hashmap.insert(s[i]);
            } else {
                hashmap.erase(s[i - 1]);
            }

            while (fast < n && !hashmap.count(s[fast])) {
                hashmap.insert(s[fast]);
                ++ fast;
            }
            res = max(res, fast - i);
        }

        return res;
    }
};