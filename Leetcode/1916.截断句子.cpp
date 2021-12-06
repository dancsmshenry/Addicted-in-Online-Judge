class Solution {
public:
    string truncateSentence(string s, int k) {
        /*统计空格，空格数减少到0的时候，就截取s的前半截输出*/
        for (int i = 0; i < s.size(); i ++ ){
            if (s[i] == ' '){
                k -- ;
            }
            if (k == 0){
                return s.substr(0, i);
            }
        }

        return s;
    }
};