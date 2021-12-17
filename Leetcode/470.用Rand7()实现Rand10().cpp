// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int result = (rand7() - 1) * 7 + rand7();
        if (result > 0 && result < 11){
            return result;
        }

        return rand10();
    }
};