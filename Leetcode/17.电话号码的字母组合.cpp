class Solution {
public:
    vector<string> letterCombinations(string digits) {
        /*
            先定义一个空的vector<string>，然后对于每一个数字里有的字母
            都把它和vector<string>里面的元素相互结合，再放入vector<string>里面
        */
        if (digits.size() == 0){
            return {};
        }
        vector<vector<string>> f{
            {"a","b","c"},
            {"d","e","f"},
            {"g","h","i"},
            {"j","k","l"},
            {"m","n","o"},
            {"p","q","r","s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"}};
        vector<string> result = {""};
        reverse(digits.begin(), digits.end());
        int n = stoi(digits);

        while (n != 0){
            int number = n % 10 - 2, length = result.size();
            vector<string> mid1 = result;
            result = {};
            for(int j = 0; j < f[number].size(); j ++ ){
                for (int i = 0; i < length; i ++ ){
                    string mid = mid1[i] + f[number][j];
                    result.push_back(mid);
                }
            }
            n /= 10;
        }

        return result;
    }
};

class Solution {
public:
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> hashmap = {{'2', {'a','b','c'}}, {'3', {'d','e','f'}}, {'4', {'g','h','i'}}, 
                                                    {'5', {'j','k','l'}}, {'6', {'m','n','o'}}, {'7', {'p','q','r','s'}}, 
                                                    {'8', {'t','u','v'}}, {'9', {'w','x','y','z'}}};
        if (digits.size() == 0) {
            return {};
        }
        string s = "";
        solve(0, hashmap, s, digits);
        return result;
    }

    void solve(int begin, unordered_map<char, vector<char>>& hashmap, string& res, string& digits) {
        if (begin == digits.size()) {
            result.push_back(res);
        }
        
        for (auto& c: hashmap[digits[begin]]) {
            res += c;
            solve(begin + 1, hashmap, res, digits);
            res.pop_back();
        }
    }
};