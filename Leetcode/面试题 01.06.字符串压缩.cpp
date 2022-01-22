class Solution {
public:
    string compressString(string S) {
        int p1 = 0, p2 = 0;
        int n = S.size();
        string res = "";

        while (p2 < n){
            while (p2 + 1 < n && S[p2] == S[p2 + 1]) p2 ++ ;
            int length = p2 - p1 + 1;
            res += S[p1];
            res += to_string(length);
            p2 ++ ;
            p1 = p2;
        }

        return res.size() < n ? res : S;
    }
};