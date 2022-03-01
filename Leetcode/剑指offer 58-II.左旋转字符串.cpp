class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res;

        for (int i = n; i < s.size() + n; ++ i ) {
            res += s[i % s.size()];
        }

        return res;
    }
};

//原地构造
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        for(int i = 0; i < n ; ++ i) {
            s.push_back(s[i]);
        }
        
        s.erase(0,n);
        
        return s;
    }
};