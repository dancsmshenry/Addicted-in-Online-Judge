class Solution {
private:
    unordered_map<char, vector<char>> hashmap = {{'2', {'a','b','c'}}, {'3', {'d','e','f'}}, {'4', {'g','h','i'}}, 
                                                 {'5', {'j','k','l'}}, {'6', {'m','n','o'}}, {'7', {'p','q','r','s'}}, 
                                                 {'8', {'t','u','v'}}, {'9', {'w','x','y','z'}}};
    vector<string> result;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        string s = "";
        solve(0, s, digits);
        return result;
    }

    void solve(int begin, string& res, string& digits) {
        if (begin == digits.size()) {
            result.push_back(res);
        }
        
        for (auto& c: hashmap[digits[begin]]) {
            res.push_back(c);
            solve(begin + 1, res, digits);
            res.pop_back();
        }
    }
};