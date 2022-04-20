class Solution {
public:
    int myAtoi(string str) {
        int result = 0, fuhao = 1, n = str.size();
        bool flag = true;

        for (int i = 0; i < n; i ++ ){
            if (flag && str[i] == ' '){//一开始，如果是空格，就跳过
                continue;
            }
            if (!flag && (str[i] < '0' || str[i] > '9')){//flag为false，str[i]不为数字，表明已经处理过了前面的数字了，直接退出
                break;
            }
            if (str[i] == '-' && i + 1 < n && (str[i + 1] >= '0' && str[i + 1] <= '9')){//数字前面是负号
                fuhao = - 1;
                continue;
            }
            if (str[i] == '+' && i + 1 < n && (str[i + 1] >= '0' && str[i + 1] <= '9')){//数字前面是正号
                continue;
            }
            if (flag && (isalpha(str[i]) || ispunct(str[i]))){//如果第一个是字符或者字母的话，就break
                break;
            }
            if (str[i] >= '0' && str[i] <= '9'){
                flag = false;
                if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (str[i] == '8' || str[i] == '9'))){
                    return fuhao == -1 ? INT_MIN : INT_MAX;
                }
                result = result * 10 + (str[i] - 48);
            }
        }

        return result * fuhao;
    }
};


class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int flag = 1;
        int n = s.length();
        while (s[i] == ' ') {//去掉空格
            ++ i;
        }

        // 前序空白符号后，紧跟着的只能是一个+或-，如果有多个+、-则判定非法，返回0
        if (s[i] == '-') {
            flag = -1;
            ++ i;
        } else if (s[i] == '+') {
            ++ i;
        }

        int res = 0;
        while (i < n && isdigit(s[i])) {// 符号之后的一定要是数字，如果为字符则非法。忽略数字最后的其他字符
            if (res > INT_MAX / 10) {//大小直接超过最大大小了
                return flag == 1 ? INT_MAX : INT_MIN;
            }

            if (res == INT_MAX / 10 && flag == 1 && (s[i] - '0') >= INT_MAX % 10) {
                return INT_MAX;
            }
            // MAX_MIN -2147483648  MAX_MAX 2147483647, 负数绝对值比正数大，此处应为>=, 否则边界情况，会溢出
            if (res == INT_MAX / 10 && flag == -1 && (s[i] - '0') >= -(INT_MIN % 10)) {
                return INT_MIN;
            }

            res = res * 10 + (s[i] - '0');//这里有个小细节，如果不加上括号的话，就会导致先加上s[i]后大小超标，出现bug....
            ++ i;
        }
        
        return res * flag;
    }
};