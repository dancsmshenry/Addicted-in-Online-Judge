class Solution {
public:
    bool isValid(string str) {
        int n = str.length();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> hashmap{{'(', ')'}, {'{', '}'}, {'[', ']'}};
        stack<char> s1;
        for (auto& s: str) {
            if (s1.empty()) {
                s1.push(s);
            } else if (hashmap.count(s1.top()) && hashmap[s1.top()] == s) {
                s1.pop();
            } else {
                s1.push(s);
            }
        }
        return s1.empty();
    }
};