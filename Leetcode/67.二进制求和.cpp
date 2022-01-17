#include <cstdlib>
class Solution {
public:
    string addBinary(string a, string b) {
        int sizea = a.size() - 1, sizeb = b.size() - 1, mid = 0;
        string res = "";

        while (sizea >= 0 && sizeb >= 0){
            int mid1 = (mid + a[sizea] - '0' + b[sizeb] - '0') / 2;
            int number = (mid + a[sizea] - '0' + b[sizeb] - '0') % 2;
            mid = mid1;
            res += to_string(number);
            sizea -- ;
            sizeb -- ;
        }

        while (sizea >= 0){
            int mid1 = (mid + a[sizea] - '0') / 2;
            int number = (mid + a[sizea] - '0') % 2;
            mid = mid1;
            res += to_string(number);
            sizea -- ;
        }

        while (sizeb >= 0){
            int mid1 = (mid + b[sizeb] - '0') / 2;
            int number = (mid + b[sizeb] - '0') % 2;
            mid = mid1;
            res += to_string(number);
            sizeb -- ;
        }

        if (mid > 0) res += to_string(mid);
        reverse(res.begin(), res.end());
        return res;
    }
};