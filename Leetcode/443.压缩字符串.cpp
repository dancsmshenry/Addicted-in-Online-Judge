class Solution {
public:
    int compress(vector<char>& chars) {
        int p1 = 0, p2 = 0, p3 = 0;//p3表示已经处理好了的字符串；p2从p1一直向右边推进，直到当前的字符不同为止；p1表示当前正在处理的字符
        int n = chars.size();

        while (p2 < n) {
            while (p2 < n && chars[p2] == chars[p1]) {
                p2 ++ ;//p2向右推进，直到第一个不等于p1位置字符的字符
            }
            chars[p3 ++ ] = chars[p1 ++ ];//先把第一个字母放回到p3的位置（p3++是因为后续也是后置++；p1++实际因为这一位用过了，就跳到下一位）
            int number = p2 - p1 + 1;//计算该字符的长度，+1是因为上卖弄也+1了
            if (number == 1) {//如果长度为1，就不加数字了，直接越过
                continue;
            }
            //下面的操作就是把计数放到字符中
            vector<char> temp;
            while (number) {
                temp.push_back(number % 10 + '0');
                number /= 10;
            }
            for (int i = temp.size() - 1; i >= 0; -- i) {
                chars[p3 ++ ] = temp[i];
            }
            //重置p1的位置，让它变为下一个字符的初始位置
            p1 = p2;
        }
        chars.resize(p3);//重置大小

        return p3;
    }
};