class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int five{}, ten{};

        for (auto& bill : bills) {
            if (bill == 5) {
                ++ five;
            } else if (bill == 10) {
                ++ ten;
                -- five;
            } else {
                -- five;
                if (ten == 0) {
                    five -= 2;
                } else {
                    -- ten;
                }
            }
            if (five < 0 || ten < 0) {
                return false;
            }
        }

        return true;
    }
};