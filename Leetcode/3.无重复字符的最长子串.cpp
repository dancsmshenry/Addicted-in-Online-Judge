class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashset;
        int res = 0;
        int right = 1;
        int n = s.size();

        for (int i = 0; i < n; i ++ ) {
            if (i > 0) {
                hashset.erase(s[i - 1]);
            }else {
                hashset.insert(s[i]);
            }

            while (right < n && !hashset.count(s[right])) {
                hashset.insert(s[right]);
                right ++ ;
            }

            res = max(res, right - i);
        }

        return res;
    }
};