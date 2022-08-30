class Solution {
public:
    int numTrees(int n) {
        vector<int> record(n + 1, 0);
        record[0] = 1;
        record[1] = 1;

        for (int i = 2; i <= n; ++ i) {
            for (int j = 0; j < i / 2; ++ j) {//    这里必须要用j=0，因为这样循环的目的，是为了模拟两边都可能出现的情况，如果是从1开始，就会略过为0的情况
                record[i] += record[j] * record[i - j - 1] * 2;
            }
            if (i % 2 == 1) {
                record[i] += record[i / 2] * record[i / 2];
            }
        }

        return record[n];
    }
};