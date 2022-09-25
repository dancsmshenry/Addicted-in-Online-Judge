class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param checkInDate string字符串 入住日期
     * @param checkOutDate string字符串 离店日期
     * @return int整型
     */    
    //  日期格式：YYYY-MM-DD
    //  计算日期之间的天数
    int daysBetweenDates(string checkInDate, string checkOutDate) {
        // write code here
        vector<int> days{31,28,31,30,31,30,31,31,30,31,30,31};
        // 左开右闭，即离开的那一天是不算入总天数的
        vector<int> begin = split(checkInDate), end = split(checkOutDate);
        
        int count{};
        while (begin[0] != end[0] || begin[1] != end[1] || begin[2] != end[2]) {
            int day = days[begin[1] - 1];
            if (begin[1] == 2 && begin[0] % 4 == 0) day = 29; // 闰年处理
            if (begin[2] + 1 <= day) { // 往后推一天，没有过到下一个月
                ++ begin[2];
            } else { // 往后推一天，到下一个月了
                begin[2] = 1; // 先调整日期
                if (begin[1] + 1 <= 12) { // 下一个月还是当年
                    ++ begin[1];
                } else { // 下一个月到了下一年了
                     ++ begin[0];
                    begin[1] = 1;
                }
            }
            ++ count;
        }
        
        return count;
    }
    
    vector<int> split(string& str) {
        string temp;
        vector<int> res;
        for (auto& s: str) {
            if (s != '-') temp += s;
            else {
                res.push_back(stoi(temp));
                temp = "";
            }
        }
        res.push_back(stoi(temp));
        return res;
    }
};