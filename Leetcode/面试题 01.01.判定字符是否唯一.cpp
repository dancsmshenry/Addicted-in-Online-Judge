class Solution {
public:
    bool isUnique(string astr){
        int n = astr.length();
        int flag[26];
        memset(flag, 0, sizeof(flag));
        
        for (int i = 0; i < n; i ++ ){
            if (flag[astr[i] - 'a'] != 0){
                return false;
            }
            ++ flag[astr[i] - 'a'];
        }

        return true;
    }
};