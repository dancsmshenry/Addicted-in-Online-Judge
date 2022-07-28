class Solution {
public:
    string convert(string s, int numRows) {
        string res{};
        if (numRows == 1) {
            return s;
        }

        for (int i = 0; i < numRows; ++ i) {
            int a = 2 * numRows - 2 - i * 2, j = i, l = 0;
            while(j < s.size()) {
                res += s[j];
                if (a == 0) {   //  遍历到当前的最后一行的时候，每次只要选择跳过固定步长的字符输入即可
                    j += (2 * numRows - 2);
                } else if (l % 2 == 0 || 2 * numRows - 2 == a) { // 后一个条件是针对当前处于第一行的情况
                // 前一个条件则是针对中间层的后一个数字（因为中间层是有两个数字的）
                    j += a;
                } else {    //  是针对中间层的前一个数字
                    j += (2 * numRows - 2 - a);
                }
                ++ l;   //  这里奇数是因为中间层，每两个数字就要往后跳一次
            }
        }

        return res;
    }
};