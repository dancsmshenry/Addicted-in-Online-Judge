class Solution {
public:
    vector<string> result;

    vector<string> permutation(string s) {
        /*又不说有没有重复的元素....*/
        /*果然有重复元素*/
        string res = {};
        solve(s, res);
        set<string> setstring(result.begin(), result.end());//去重
        result.assign(setstring.begin(), setstring.end());
        return result;
    }

    void solve(string& s, string& res){
        for (int i = 0; i < s.size(); i ++ ){
            if (s[i] == '\n'){
                continue;
            }
            char s1 = s[i];
            res += s1;
            s[i] = '\n';
            if (res.size() < s.size()){
                solve(s, res);
            }else{
                result.push_back(res);
            }
            s[i] = s1;
            res.erase(res.end() - 1);//删除最后一个元素
        }
    }
};