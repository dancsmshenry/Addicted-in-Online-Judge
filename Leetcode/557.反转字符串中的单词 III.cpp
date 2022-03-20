class Solution {
public:
    string reverseWords(string s) {
        int slow = 0, fast = 0;
        int n = s.size();

        while (fast < n){
            while (fast < n && s[fast] != ' ') fast ++ ;
            reverse(s.begin() + slow, s.begin() + fast);
            fast ++ ;
            slow = fast;
        }

        return s;
    }
};