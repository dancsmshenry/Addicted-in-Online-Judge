class Solution {
public:
    int strToInt(string str) {
        int result = 0, fuhao = 1, n = str.size();
        bool flag = true;

        for (int i = 0; i < n; i ++ ){
            if (flag && str[i] == ' '){//一开始，如果是空格，就跳过
                continue;
            }
            if (!flag && (str[i] < '0' || str[i] > '9')){//flag为false，str[i]不为数字，表明已经处理过了前面的数字了，直接退出
                break;
            }
            if (str[i] == '+' || str[i] == '-'){//数字前面是正号或负号
                if (i + 1 < n && (str[i + 1] >= '0' && str[i + 1] <= '9')){
                    fuhao = str[i] == '-' ? -1 : 1;
                    continue;
                }
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