class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> f(s.size() + 1, vector<int> (p.size() + 1, 0));
        f[0][0] = 1;
        auto match=[&](int i, int j){
            if (i == 0){
                return false;
            }
            if (p[j - 1] == '.'){
                return true;
            }
            return s[i - 1] == p[j - 1];
        };
    
        for (int i = 0; i <= s.size(); i ++ ){
            for (int j = 1; j <= p.size(); j ++ ){
                if (p[j - 1] == '*'){
                    f[i][j] |= f[i][j - 2];
                    if (match(i, j - 1)){//这一步太精髓了.....
                        f[i][j] |= f[i - 1][j];
                    }
                }else{
                    if (match(i, j)){
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }

        return f[s.size()][p.size()];
    }
};
//后续补上一个用滚动数组的做法，非常的有趣（好吧，我错了，这个滚动数组有点麻烦）