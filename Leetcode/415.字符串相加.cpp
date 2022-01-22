class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size() - 1, n2 = num2.size() - 1;
        int carry = 0;
        string res = "";

        while (n1 >= 0 || n2 >= 0){
            int number = carry;
            if (n1 >= 0) number += (num1[n1] - '0');
            if (n2 >= 0) number += (num2[n2] - '0');
            res+= to_string(number % 10);
            carry = number / 10;
            n1 -- ;
            n2 -- ;
        }
        if (carry > 0) res += to_string(carry);

        reverse(res.begin(), res.end());
        return res;
    }
};