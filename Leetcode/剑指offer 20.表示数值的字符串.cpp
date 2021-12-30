class Solution {
public:
    bool isNumber(string s) {
        bool xiaoshudian = true, flag = true, flage = true;
        int fuhao = 0;
        s.insert(0, " ");//给字符串前面加上一些空格，方便后续对空格的处理
        for (int j = s.size() - 1; j >= 0 && s[j] == ' '; j -- ) s.pop_back();//这里主要是把后面的空格给去掉，方便后续的边界处理（bug1：这里没考虑到边界问题，j为-1就报错了）

        for (int i = 0; i < s.size(); i ++ ){
            if (isalpha(s[i]) != 0 && s[i] != 'e' && s[i] != 'E') return false;//如果是其他的字母，直接false
            if (s[i] == ' '){
                if (flag == false) return false;//在空格后面的数据不能再有空格了，否则就false
                if (i + 1 < s.size() && s[i + 1] != ' ') flag = false;//对于所有的空格，只能有一个空格的后面有数据，如果当前空格后面有数据，就flag记录一下
            }else if (s[i] == '+' || s[i] == '-'){
                if ( ++ fuhao > 2) return false;//一个字符串中只能有两个符号，超过了就false
                if (i + 1 >= s.size() || (s[i + 1] == 'E' || s[i + 1] == 'e')) return false;//符号后面只能跟数字或小数点，所以符号后面没有东西或为eE的，直接false
                if (s[i - 1] != ' ' && (s[i - 1] != 'e' && s[i - 1] != 'E')) return false;//符号前面只能是空格，或者eE，其他的直接false
            }else if (s[i] == 'e' || s[i] == 'E'){
                if (s[i - 1] == ' ' || i + 1 >= s.size() || flage == false) return false;//不能有单独的一个eE的，eE后面要有数据，或者有多于一个，否则false
                if (!((s[i + 1] >= '0' && s[i + 1] <= '9') || s[i + 1] == '+' || s[i + 1] == '-')) return false;//eE的前面必须是数字或者+-号，否则false
                xiaoshudian = false;//有了eE后，就不能再有小数点了
                flage = false;//有了一个e之后直接设置flage为false
            }else if (s[i] == '.'){
                if (xiaoshudian == false) return false;//因为只能有一个小数点，所以如果多于一个，false
                xiaoshudian = false;//遇到第一个小数点，设为false
                if ((i == s.size() - 1) && (s[i - 1] == ' ')) return false;//如果只有一个小数点，直接false
                if (i + 1 < s.size() && (s[i + 1] > '9' || s[i + 1] < '0') && s[i + 1] != 'e' && s[i + 1] != 'E') return false;//小数点后面，要么是数字，要么就直接啥都没有，否则false
                if ((s[i - 1] > '9' || s[i - 1] < '0') && ((i + 1 < s.size() && (s[i + 1] > '9' || s[i + 1] < '0')) || i == s.size() - 1)) return false;//前后都没有数字，直接false
            }
        }
        
        return flag == true ? false : true;//为了防止空串的情况（如果是空串，flag就是true）
    }
};
//写完这道题，我的感受是，一定要学会有限状态机.........