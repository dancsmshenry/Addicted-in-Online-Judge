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
            } else {
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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxn = 0, point1 = 0, point2 = 1;
        if (n < 2) {
            return n;
        } 

        while (point2 < n) {
            for (int i = point1; i < point2; ++ i) {
                if (s[i] == s[point2]) {
                    point1 = i + 1;
                    break;
                }
            }
            maxn = max(point2 - point1 + 1, maxn);
            ++ point2;
        }

        return maxn;
    }
};