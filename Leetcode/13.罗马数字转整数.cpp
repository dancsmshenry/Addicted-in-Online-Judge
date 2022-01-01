class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hashmap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = hashmap[s[s.size() - 1]];
        cout << result << endl;

        for (int i = s.size() - 2; i >= 0; i -- ){
            if (hashmap[s[i]] < hashmap[s[i + 1]]){
                result -= hashmap[s[i]];
            }else{
                result += hashmap[s[i]];
            }
        }

        return result;
    }
};