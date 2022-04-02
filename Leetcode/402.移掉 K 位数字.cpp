class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) {
            return "0";
        }

        string stk = "";
        for (auto& digit: num) {
            while (stk.size() > 0 && stk.back() > digit && k) {
                stk.pop_back();
                -- k;
            }
            if (stk.size() == 0 && digit == '0') {
                continue;
            }
            stk.push_back(digit);
        }

        for (; k > 0 && !stk.empty(); -- k) {
            stk.pop_back();
        }

        return stk == "" ? "0" : stk;
    }
};