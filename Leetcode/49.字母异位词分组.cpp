class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> flag(strs.size(), 0);
        vector<vector<string>> result;
        solve(flag, strs, result);
        return result;
    }

    void solve(vector<int>& flag, vector<string>& strs, vector<vector<string>>& result){
        int begin = 0;
        while (begin < strs.size() && flag[begin] == 1) begin ++ ;
        if (begin == strs.size()){
            return ;
        }
        unordered_map<char, int> map;
        for (const char& ch: strs[begin]){
            map[ch] ++ ;
        }
        flag[begin] = 1;
        vector<string> s1 = {strs[begin]};
        for (begin += 1;begin < strs.size(); begin ++ ){
            if (flag[begin] == 1) continue;
            unordered_map<char, int> map1;
            bool t = false;
            for (const char& ch: strs[begin]){
                map1[ch] ++ ;
            }
            for (const char& ch: s1[0]){//这里应该是以最开始的模板做对比，如果出现元素在map里面出现，map1里面没出现，就退出；或者都出现了，但是数量不对，也退出
                if (map1.find(ch) == map1.end() || map1[ch] != map[ch]){
                    t = true;
                    break;
                }
            }
            if (t == false && s1[0].size() == strs[begin].size()){//注意，可能会出现""的情况
                s1.push_back(strs[begin]);
                flag[begin] = 1;
            }
        }
        result.push_back(s1);
        solve(flag, strs, result);
    }
};//该方法超时了....


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*解题思路的大前提：分为一组的单词对其字母进行排序后，得到的结果都是一样的*/
        unordered_map<string, vector<string>> map;

        for (const string& str: strs){
            string key = str;
            sort(key.begin(), key.end());
            map[key].emplace_back(str);
        }

        vector<vector<string>> result;
        for (auto& vec: map){
            result.push_back(vec.second);
        }
        
        return result;
    }
};