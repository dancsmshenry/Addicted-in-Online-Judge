class Solution {
public:
    string thousandSeparator(int n) {
        string res = "";
        int count = 0;

        do {
            res += to_string(n % 10);
            n /= 10;
            count ++ ;
            if (count % 3 == 0 && n != 0) {
                res += ".";
            }
        } while (n > 0);

        reverse(res.begin(), res.end());

        return res;
    }
};