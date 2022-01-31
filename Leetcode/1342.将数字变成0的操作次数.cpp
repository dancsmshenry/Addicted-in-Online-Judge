class Solution {
public:
    int numberOfSteps(int num) {//注意0
        int res = 0;

        do {
            if ((num & 1) == 0) {//注意&和==的优先级
                res ++ ;
            } else {
                res += 2;
            }
            num = num >> 1;
        } while (num != 0);

        return res - 1;
    }
};