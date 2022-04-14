class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());// 反转整个字符串

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++ start) {
            if (s[start] != ' ') {
                if (idx != 0) {// 填一个空白字符然后将idx移动到下一个单词的开头位置
                    s[idx] = ' ';
                    ++ idx;
                }

                int end = start, begin = idx;
                while (end < n && s[end] != ' ') {// 循环遍历至单词的末尾
                    s[idx] = s[end];
                    ++ idx;
                    ++ end;
                }
                
                reverse(s.begin() + begin, s.begin() + idx);//反转整个单词，begin是单词开始的位置，此时的idx是单词的末尾
                
                start = end;// 更新start，去找下一个单词
            }
        }
        s.erase(s.begin() + idx, s.end());
        
        return s;
    }
};