class Solution {
public:
    string replaceSpace(string s) {
        string res = "";

        for (auto& s1: s) {
            if (s1 != ' ') {
                res += s1;
            } else {
                res += "%20";
            }
        }

        return res;
    }
};

/* 原地扩容 */
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0, len = s.size();
        
        for (char c : s) {//统计空格数量
            if (c == ' ') {
                count ++ ;
            }
        }
        
        s.resize(len + 2 * count);//扩容
        for(int i = len - 1, j = s.size() - 1; i < j; i -- , j -- ) {
            if (s[i] != ' ') {
                s[j] = s[i];
            } else {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }
        
        return s;
    }
};