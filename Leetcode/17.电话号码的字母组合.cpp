#include <cstdlib>

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