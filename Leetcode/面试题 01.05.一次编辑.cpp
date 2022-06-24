class Solution {
public:
    bool oneEditAway(string first, string second) {
        int length1 = first.length(), length2 = second.length();
        if (abs(length1 - length2) > 1) {
            return false;
        }

        bool flag = false;
        for (int p1 = 0, p2 = 0; p1 < length1 && p2 < length2; ++ p1, ++ p2) {
            if (first[p1] != second[p2]) {
                if (flag) {
                    return false;
                }
                if (length2 > length1) {
                    -- p1; 
                } else if (length2 < length1) {
                    -- p2;
                }
                flag = true;
            }
        }

        return true;
    }
};