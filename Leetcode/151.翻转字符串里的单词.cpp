class Solution {
public:
    string reverseWords(string s) {
        vector<string> res(1, "");
        string result = "";

        for (int i = 0, j = 0; i < s.size(); i ++ ){
            char s2 = s[i];
            if (s2 == ' '){
                res.push_back("");
                j ++ ;
            }else{
                char s1 = s[i];
                res[j] += s1;
            }
        }
        
        for (int i = res.size() - 1; i >= 0; i -- ){
            if (res[i] != ""){
                result += (res[i] + " ");
            }
        }
        result = result.substr(0, result.length() - 1);

        return result;
    }
};