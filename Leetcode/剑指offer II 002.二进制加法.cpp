class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";

        int n = a.size(), m = b.size();
        for (int i = n - 1, j = m - 1, count = 0; i >= 0 || j >= 0 || count;) {
            if (i >= 0) {
                count = count + (a[i] - '0');
                -- i;
            }
            if (j >= 0) {
                count = count + (b[j] - '0');
                -- j;
            }
            res += to_string(count % 2);
            count /= 2;
        }
        reverse(res.begin(), res.end());

        return res;
    }
};