class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int begin = 0, end = n - 1; begin < end; ++ begin, -- end) {
            swap(s[begin], s[end]);
        }
    }
};