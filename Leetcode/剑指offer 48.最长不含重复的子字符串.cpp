class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashmap;
        int n = s.size();
        int res = 0;
        int right = 1;

        for (int i = 0; i < n; ++ i) {
            if (i == 0) {
                hashmap.insert(s[i]);
            } else {
                hashmap.erase(s[i - 1]);
            }

            while (right < n && !hashmap.count(s[right])) {
                hashmap.insert(s[right]);
                ++ right;
            }

            res = max(res, right - i);
        }

        return res;
    }
};