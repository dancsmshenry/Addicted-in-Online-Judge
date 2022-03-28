// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int result = (rand7() - 1) * 7 + rand7() - 1;
        if (result > 0 && result < 41){
            return result % 10 + 1;
        }

        result = (result % 40) * 7 + rand7();
        if (result <= 60) {
            return result % 10 + 1;
        }

        return rand10();
    }
};