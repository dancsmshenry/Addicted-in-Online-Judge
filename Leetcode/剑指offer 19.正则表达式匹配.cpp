class Solution {
public:
    bool isMatch(string s, string p){
        /*这道题和编辑距离很像啊，几乎是一个模板思路套过来的*/
        int m = s.size(), n = p.size();
        //ps：这里的值默认的初始化都是0；同时为了方便处理边界问题，下标都是从0-m，0-n的，所以后续映射到字符数组上，都是i-1和j-1
        vector<vector<int>> f(m + 1, vector<int>(n + 1));

        //当两个都是空的时候，肯定可以匹配的上的，直接是true
        f[0][0] = true;

        //用于匹配字符的函数
        auto matches = [&](int i, int j){
            //排除f[0][0]，后面只要是i=0的，都是false（因为s都没有字符）
            if (i == 0){
                return false;
            }
            //如果是.，那么直接true，因为.可以表示任意一个字符
            if (p[j - 1] == '.'){
                return true;
            }
            //否则的话，就是返回两个字母值的比较
            return s[i - 1] == p[j - 1];
        };
        
        for (int i = 0; i <= m; i ++ ){
            //这里i就要从1开始，因为初始化的时候，全部都是0了
            for (int j = 1; j <= n; j ++ ){
                //前提：*可以匹配任意数量的字符（*不会出现在最前面，所以j不会越界）
                if (p[j - 1] == '*'){
                    //这里假设*表示前面的字符出现了0次，所以j和j-1都忽略掉了，直接比较包括j-2的前半部分
                    f[i][j] |= f[i][j - 2];
                    //这里是精髓，如果第i个和第j-1个相等，则可以或运算f[i-1][j](这个地方需要不断的思考，太巧妙了...)
                    if (matches(i, j - 1)){
                        f[i][j] |= f[i - 1][j];
                    }
                }else{//如果不是*，那就是单纯的字符比较，看是否match即可
                    if (matches(i, j)){
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }

        return f[m][n];
    }
};